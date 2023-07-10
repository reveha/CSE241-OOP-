#include "tetris_board.hpp"

// Turn input to tetromino
D1Tms xturn_table = {
    Tms::I,
    Tms::O,
    Tms::T,
    Tms::J,
    Tms::L,
    Tms::S,
    Tms::Z,
    Tms::Random};
// Check input
std::vector<char> xvalid_values = {
    'I',
    'O',
    'T',
    'J',
    'L',
    'S',
    'Z',
    'R'};

#pragma region NodeMap
// Pathfinding algroith

// Reset Nodes
void NodeMap::UpdateNodes()
{
    for (int j = 0; j < this->size.y; j++)
    {
        for (int i = 0; i < this->size.x; i++)
        {
            this->Map[j][i].H_cost = INT16_MAX;
            this->Map[j][i].G_cost = INT16_MAX;
            this->Map[j][i].F_cost = INT16_MAX;
            this->Map[j][i].parent = {i, j};
            this->closed[j][i] = 0;
        }
    }
}
// Check the location inside of board and empyt
bool NodeMap::check_valid(const Dual &Loc, const Tetromino &piece)
{
    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < piece.size.y; j++)
        {
            if (piece.piece[j][i] != Tms::X)
            {
                if (Loc.x + i >= this->size.x || Loc.x + i < 0)
                    return false;
                if (Loc.y + j >= this->size.y || Loc.y + j < 0)
                    return false;
                if (this->Map[Loc.y + j][Loc.x + i].isFull)
                    return false;
            }
        }
    }
    return true;
}
// Draw the path 
void NodeMap::trace_path(const Dual &desc)
{
    this->Path.clear();
    Dual temp = desc;

    while (!(temp == this->at(temp).parent))
    {
        this->Path.push_back(temp);
        temp = this->at(temp).parent;
    }
    this->Path.push_back(temp);
}
// Pathfind to given destination with considering the tetromino shape
bool NodeMap::PathFinder(const Dual &loc, const Dual &desc, const Tetromino &piece)
{
    this->UpdateNodes();
    if (!check_valid(loc, piece))
        return false;

    if (!check_valid(desc, piece))
        return false;

    if (desc == loc)
        return true;

    D1Dual open_list;
    open_list.push_back(loc);

    this->at(loc).G_cost = 0;
    this->at(loc).H_cost = loc | desc;
    this->at(loc).F_cost = loc | desc;
    this->at(loc).parent = loc;

    while (!open_list.empty())
    {
        Dual test = open_list[0];
        open_list.erase(open_list.begin());

        this->closed[loc.y][loc.x] = 2;

        int h, g, f;

        for (int a = 0; a < 3; a++)
        {
            Dual i = 0;
            if (a == 0)
                i = {-1, 0};
            else if (a == 1)
                i = {1, 0};
            else if (a == 2)
                i = {0, 1};
            if (check_valid(test + i, piece))
            {
                if (test + i == desc)
                {
                    this->at(test + i).parent = test;
                    this->at(test + i).F_cost = 0;
                    trace_path(desc);
                    return true;
                }
                else
                {
                    g = this->at(test).G_cost + 1;
                    h = (test + i) | desc;
                    f = g + h;
                    if (this->at(test + i).F_cost > f)
                    {
                        open_list.push_back(test + i);
                        this->at(test + i).F_cost = f;
                        this->at(test + i).H_cost = h;
                        this->at(test + i).G_cost = g;
                        this->at(test + i).parent = test;
                    }
                }
            }
        }
    }
    return false;
}
// Easily access to nodes
Node &NodeMap::at(const Dual &desc)
{
    return this->Map[desc.y][desc.x];
}
#pragma endregion

#pragma region TetrisBoard
// Constructor
TetrisBoard::TetrisBoard(int i, int j) : size(i, j), nodes(i, j)
{
    tms_map = D2Tms(j, D1Tms(i, Tms::X));
}
// Move the pieces to given location without animation
Dual TetrisBoard::move(Tetromino &piece, const Dual &cursor, const Dual &Goal)
{
    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < piece.size.y; j++)
        {
            if (piece.piece[j][i] != Tms::X)
            {
                this->tms_map[cursor.y + j][cursor.x + i] = Tms::X;
            }
        }
    }

    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < piece.size.y; j++)
        {
            if (piece.piece[j][i] != Tms::X)
            {
                this->tms_map[Goal.y + j][Goal.x + i] = piece.piece[j][i];
            }
        }
    }
    return Goal;
}
// Animate the piece
void TetrisBoard::Animate(Tetromino piece, const D1Dual &path, Dual Location)
{
    int rrr = 0;
    for (auto x : path)
    {
        rrr + x.r;
        this->Draw();
        Dual temp = x;
        temp.r = (rrr-- > 0) ? 1 : 0;
        Location = this->move(piece, Location, temp);
#ifdef SLEEP
#ifndef DEBUG
        usleep(50000);
#endif
#endif
    }
    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < piece.size.y; j++)
        {
            if (piece.piece[j][i] != Tms::X)
            {
                this->nodes.Map[Location.y + j][Location.x + i].isFull = true;
            }
        }
    }
    for (int j = this->size.y - this->maximum_height; j < this->size.y; j++)
    {
        bool canShrink = true;
        for (int i = 0; i < this->size.x; i++)
        {
            if (this->tms_map[j][i] == Tms::X)
            {
                canShrink = false;
                break;
            }
        }
        if (canShrink)
        {
            this->tms_map.erase(this->tms_map.begin() + j);
            this->nodes.Map.erase(this->nodes.Map.begin() + j);

            this->tms_map.insert(this->tms_map.begin(), D1Tms(this->size.x, Tms::X));
            this->nodes.Map.insert(this->nodes.Map.begin(), D1Node(this->size.x));
            this->maximum_height--;
        }
    }
    this->Draw();
}
// Choose the best destination to piece and start Animate function
bool TetrisBoard::Fit(Tetromino piece)
{
    Dual Location = {this->size.x / 2 - 1, 0};
    D1Dual best_path(1);
    int best_st = INT16_MAX;
    for (int r = 0; r < 4; r++)
    {
        for (int j = this->size.y - this->maximum_height - piece.size.y; j < this->size.y - piece.size.y + 1; j++)
        {
            if (j < 0)
                j = 0;
            for (int i = 0; i < this->size.x - piece.size.x + 1; i++)
            {
                bool canFit = true;
                for (int jj = 0; jj < piece.size.y; jj++)
                {
                    for (int ii = 0; ii < piece.size.x; ii++)
                    {
                        if (this->tms_map[j + jj][i + ii] != Tms::X && piece.piece[jj][ii] != Tms::X)
                        {
                            canFit = false;
                        }
                    }
                }
                if (canFit)
                {
                    if (this->nodes.PathFinder(Location, {i, j}, piece))
                    {
                        D1int temp_best;
                        int temp_st = this->StateCalculator({i, j, r}, piece);
                        if (best_st >= temp_st)
                        {
                            best_path = this->nodes.Path;
                            best_path[0].r = r;
                            best_st = temp_st;
                        }
                    }
                }
            }
        }
        piece.rotate();
    }
    if (best_st == INT16_MAX || best_st == 0)
        return false;
    
    for (int i = 0; i < best_path[0].r; i++)
    {
        piece.rotate();
    }
    this->Add(piece);
    D1Dual temp_best_path = best_path;
    for (auto &x : best_path)
    {
        x = temp_best_path.back();
        temp_best_path.pop_back();
    }
    Tetromino tempppppp = piece;
    for (int j = 0; j < tempppppp.size.y; j++)
    {
        for (int i = 0; i < tempppppp.size.x; i++)
        {
            if (tempppppp.piece[j][i] != Tms::X)
                this->tms_map[best_path.back().y + j][best_path.back().x + i] = tempppppp.ghost;
        }
    }

    if (this->maximum_height < this->size.y - best_path.back().y)
    {
        this->maximum_height = this->size.y - best_path.back().y;
    }
    this->Add(piece);
    this->Animate(piece, best_path, Location);
    return true;
}
// Add to the start
Dual TetrisBoard::Add(const Tetromino &piece)
{
    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < piece.size.y; j++)
        {
            if (piece.piece[j][i] != Tms::X)
            {
                this->tms_map[j][this->size.x / 2 + i - 1] = piece.piece[j][i];
            }
        }
    }
    return Dual(this->size.x / 2 - 1, 0);
}

// Draw the board
void TetrisBoard::Draw(int i) const
{
    if (i == 0) std::cout << "\033["<< this->size.y + 1<<"A\033[0G\033[2K";
    for (int j = 0; j < this->size.y; j++)
    {
        for (int i = 0; i < this->size.x; i++)
        {
            Tetromino::special_print(this->tms_map[j][i], i);
        }
        putchar('\n');
    }
    putchar('\n');
}

// Calculate the position to learn which one is the best
int TetrisBoard::StateCalculator(const Dual &loc, const Tetromino &piece)
{
    int empyt_spaces = 0;
    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < this->size.y - loc.y; j++)
            if (j >= piece.size.y || piece.piece[j][i] == Tms::X)
                if (!this->nodes.Map[loc.y + j][loc.x + i].isFull)
                    empyt_spaces++;
    }

    int height_difference = 0;
    for (int i = 0; i < piece.size.x; i++)
    {
        int prev_high = piece.size.y;
        for (int j = 0; j < this->size.y - loc.y; j++)
        {
            if (this->nodes.Map[loc.y + j][loc.x + i].isFull)
            {
                prev_high = j;
                break;
            }
        }
        height_difference += prev_high;

        for (int j = 0; j < piece.size.y; j++)
        {
            if (piece.piece[j][i] != Tms::X)
            {
                prev_high = j;
                break;
            }
        }
        height_difference -= prev_high;
    }

    int closed_empyt_spaces = 0;
    if (loc.y + piece.size.y + 1 < this->size.y)
    {
        for (int i = 0; i < piece.size.x; i++)
        {
            if (piece.piece[piece.size.y - 1][i] != Tms::X)
            {
                if (!this->nodes.Map[loc.y + piece.size.y][loc.x + i + 1].isFull)
                {
                    closed_empyt_spaces++;
                }
            }
            else
            {
                closed_empyt_spaces++;
            }
        }
    }

    int doluluk = 0;// ??????
    for (int i = 0; i < piece.size.x; i++)
    {
        for (int j = 0; j < piece.size.y + 1; j++)
        {
            if (loc.x + i >= 0 && loc.x + i < this->size.x && loc.y + j >= 0 && loc.y + j < this->size.y)
            {
                if (this->tms_map[loc.y][loc.x] != Tms::X)
                {
                    doluluk++;
                }
            }
            else
            {
                doluluk++;
            }
        }
    }

    return 1 * (this->size.y - loc.y) +
           2 * (-this->size.y) +
           1 * (empyt_spaces) +
           3 * (height_difference) +
           6 * (closed_empyt_spaces) +
           1 * (-doluluk);
}
#pragma endregion
