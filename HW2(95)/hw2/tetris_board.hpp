#ifndef TETRIS_BOARD
#define TETRIS_BOARD

#include "tetromino.hpp"

#pragma region
extern std::vector<char> xvalid_values;
extern D1Tms xturn_table;
#pragma endregion

/**
 * @brief Nodes for pathfingding
 * F cost is distance to destination
 */
class Node
{
public:
    bool isFull; // Is there a anything in that node

    int G_cost;
    int H_cost;
    int F_cost;
    Dual parent;

    Node()
    {
        this->isFull = false;
    }
};

typedef std::vector<Node> D1Node;
typedef std::vector<D1Node> D2Node;

typedef std::vector<bool> D1Bool;
typedef std::vector<D1Bool> D2Bool;

// Main map for nodes
class NodeMap
{
public:
    D1Dual Path;     // Path from start to end
    D2Node Map;      // Node map for board
    const Dual size; // Size of map
    D2int closed;    // Closed nodes

    NodeMap(const Dual &size) : size(size)
    {
        Map = D2Node(this->size.y, D1Node(this->size.x));
        closed = D2int(this->size.y, D1int(this->size.x));
    }
    NodeMap(const int i, const int j) : size(i, j)
    {
        Map = D2Node(this->size.y, D1Node(this->size.x));
        closed = D2int(this->size.y, D1int(this->size.x));
    }

    Node &at(const Dual &); // Easy access to nodes
    // Pathfinding algroith
    bool PathFinder(const Dual &, const Dual &, const Tetromino & = Tetromino(Tms::B));
    // Reset nodes
    void UpdateNodes();
    // Validation check of location
    bool check_valid(const Dual &, const Tetromino & = Tetromino(Tms::B));
    // Draw a path
    void trace_path(const Dual &);
};

class TetrisBoard
{
private:
    D2Tms tms_map; // Board of tetrominos
    NodeMap nodes; // Board of nodes
    const Dual size; // Board size
    int maximum_height = 0; // Maximum height of the pieces on the board
    Dual move(Tetromino &, const Dual &, const Dual &); // Move the pieces one step
    int StateCalculator(const Dual &, const Tetromino &); // Calculate the positions

public:
    void Draw(int = 0) const; // Draw to the screen
    TetrisBoard(int = 10, int = 10);
    void Animate(Tetromino, const D1Dual &, Dual); // Move with animate
    Dual Add(const Tetromino &); // Add to the middle of first row
    bool Fit(Tetromino = Tetromino(Tms::Random)); // Add piece to board and run animate
};

#endif