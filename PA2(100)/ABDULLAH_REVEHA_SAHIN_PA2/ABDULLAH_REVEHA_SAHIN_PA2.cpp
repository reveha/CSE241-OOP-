#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class pixels{ // My pixel class to keep datas

public: // Getters and Setters
    
    double getR()const;
    double getG()const;
    double getB()const;
    void setR(int R);
    void setG(int G);
    void setB(int B);

private:

    double r,g,b;

};


class image{ // Image Class

public:
   
    image(); // Empty Constructor
    void setName(string eName);
    int getW()const;
    int getH()const;
    void openImage(); // Option 1
    void saveImage()const; // Option 2
    void scripts(); // Option 3
    void menu(); // User input menu
    void print(); // To print values of ppm file

private:

    int maxValue; // 255
    int width,height;
    string file_name; // To keep file name
    vector< vector<pixels>> picture; // My 2D Vector of pixels

};

double pixels::getR()const{return r;}
double pixels::getG()const{return g;}
double pixels::getB()const{return b;}
void pixels::setR(int R){this->r=R;}
void pixels::setG(int G){this->g=G;}
void pixels::setB(int B){this->b=B;}

image::image(){}

void image::print(){
    for(int i=0;i<height;i++){ // Basic nested loop
        for(int j=0;j<height;j++){
            cout<<picture[i][j].getR()<<" "<<picture[i][j].getG()<<" "<<picture[i][j].getB()<<" ";
        }
        cout<<endl;
    }
}


void image::openImage(){

    ifstream file(file_name); // File which will be opened

    if(!file.is_open()){ // Just printing unable to open error
        cerr<<"Unable to open file!"<<endl;
        exit(0);
    }

    string ps;
    file>>ps>>width>>height>>maxValue; // Gettin values from ppm file
    //cout<<ps;
    

    picture.resize(height,vector<pixels>(width)); // Resizeing vector 
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){ // Filling vector
            int r,g,b;
            file>>r>>g>>b;
            picture[i][j].setR(r);
            picture[i][j].setG(g);
            picture[i][j].setB(b);
        }
    }

    file.close();
    //print();

}

void image::saveImage()const{

    ofstream file(file_name); // Opening file to save ppm file

    if(!file.is_open()){ // Just printing unable to open error
        cerr<<"Unable to open file!"<<endl; 
        exit(0);
    }

    file<<"P3"<<endl;
    file<<width<<" "<<height<<endl<<"255"<<endl; // Writing informations to ppm file

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){ // Writing pixel values to ppm file
            file<<picture[i][j].getR()<<" ";
            file<<picture[i][j].getG()<<" ";
            file<<picture[i][j].getB()<<"\t";
        }
        file<<endl;
    }

    file.close();
}

void image::scripts(){

    double c_r,c_g,c_b;

    while(true){ // Getting the values from user until they entered 3 valid input
        cin>>c_r>>c_g>>c_b;
        if(c_r<0.0 || c_r>=1.0 || c_g<0.0 || c_g>=1.0 || c_b<0.0 || c_b>=1.0) {
            continue;
        }
        else{
            break;
        }
    }
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){ // Converting pixel values to new ones
            int RED,BLUE,GREEN; // To keep old values to use in the formula;
            RED=(int)picture[i][j].getR();
            GREEN=(int)picture[i][j].getG();
            BLUE=(int)picture[i][j].getB();

            // Assigning new pixel values to vector array
            picture[i][j].setR((int)(c_r*RED)+(int)(c_g*GREEN)+(int)(c_b*BLUE));
            picture[i][j].setG((int)(c_r*RED)+(int)(c_g*GREEN)+(int)(c_b*BLUE));
            picture[i][j].setB((int)(c_r*RED)+(int)(c_g*GREEN)+(int)(c_b*BLUE));

            if(picture[i][j].getR()>255){ // Checking if greater than 255
                picture[i][j].setR(255);
            }
            if(picture[i][j].getG()>255){
                picture[i][j].setG(255);
            }
            if(picture[i][j].getB()>255){
                picture[i][j].setB(255);
            }

        }
    }
    print();
}


void image:: menu(){

    string choice;

    while(true){ // Main menu program

        cout<<"MAIN MENU"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<"1 - Open An Image(D)"<<endl;
        cout<<"2 - Save Image Data(D)"<<endl;
        cout<<"3 - Scripts(D)"<<endl;

        cin>>choice;

        if(choice=="0"){ // GOOD BYE
            exit(0);
        }
        else if(choice=="1"){ // OPTION1
            while(true){
                cout<<"0 - UP"<<endl;
                cout<<"1 - Enter The Name Of The Image File"<<endl;
                cin>>choice;
                if(choice=="0")
                    break;
                else if(choice=="1"){
                    cin>>file_name;
                    openImage();
                }
            }
            
        }
        else if(choice=="2"){ // OPTION2
            while(true){
                cout<<"0 - UP"<<endl;
                cout<<"1 - Enter A File Name"<<endl;
                cin>>choice;
                if(choice=="0")
                    break;
                else if(choice=="1"){
                    cin>>file_name;
                    saveImage();
                }
            }
        }
        else if(choice=="3"){ //OPTION3
            while(true){
                cout<<"0 - UP"<<endl;
                cout<<"1 - Enter Coefficients For RED GREEN And BLUE Channels."<<endl;
                cin>>choice;
                if(choice=="0")
                    break;
                else if(choice=="1"){
                    scripts();
                }
            }
        }
        else{
            cerr<<endl;
        }
    }
}




int main(){

    image img1; // Creating an image object
    img1.menu(); 
    

    return 0;
}