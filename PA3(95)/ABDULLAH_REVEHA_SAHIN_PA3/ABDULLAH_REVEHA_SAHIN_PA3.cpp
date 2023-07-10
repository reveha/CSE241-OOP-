#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class pixels{ // My pixel class to keep datas

public: // Getters and Setters
    
    int getR()const;
    int getG()const;
    int getB()const;
    void setR(int R);
    void setG(int G);
    void setB(int B);

private:

    int r,g,b;

};


class ppmImage{ // ppmImage Class

public:
   
    ppmImage(); // Empty Constructor
    ppmImage(const string ppm_name);
    ppmImage(const int W, const int H);
    void setName(const string eName);
    void setW(const int W);
    void setH(const int H);
    string getName()const;
    int getW()const;
    int getH()const;
    vector< vector<pixels>>& getPic();
    bool readPpmValues(); // Option 1
    bool writePpmValues()const; // Option 2
    bool writePpmValues(const string f_name)const;
    void scripts(); // Option 3
    void menu(); // User input menu
    void print()const; // To print values of ppm file
    
    ppmImage operator+(const ppmImage& oth); // Operator + overload
    ppmImage operator-(const ppmImage& oth); // Operator - overload
    friend ostream& operator<<(ostream& out,  ppmImage& obj); // Operator << overload 
    int operator()(const int h, const int w, const int index)const; // Operator () overload

private:

    int maxValue; // 255
    int width,height;
    string file_name; // To keep file name
    vector< vector<pixels>> picture; // My 2D Vector of pixels


};

int pixels::getR()const{return r;}
int pixels::getG()const{return g;}
int pixels::getB()const{return b;}
void pixels::setR(int R){this->r=R;}
void pixels::setG(int G){this->g=G;}
void pixels::setB(int B){this->b=B;}


void ppmImage::setName(const string eName){this->file_name=eName;}
void ppmImage::setW(const int W){this->width=W;}
void ppmImage::setH(const int H){this->height=H;} 
string ppmImage::getName()const{return file_name;}
int ppmImage::getW()const{return width;}
int ppmImage::getH()const{return height;}
vector< vector<pixels>>& ppmImage::getPic(){return picture;}


ppmImage::ppmImage(){maxValue=255;}

ppmImage::ppmImage(const string ppm_name){
    if(ppm_name[ppm_name.length()-1]!='m' || ppm_name[ppm_name.length()-2]!='p' ||
    ppm_name[ppm_name.length()-3]!='p' || ppm_name[ppm_name.length()-4]!='.'){ // Checking the name is valid or not
        cerr<<"Invalid file name;"<<endl;
        exit(0);
    }
    this->file_name=ppm_name;
    //cout<<file_name<<endl;
    maxValue=255;
}

ppmImage::ppmImage(const int W, const int H){
    if(W<=0 || H<=0){ // Checking the sizes 
        cerr<<"Invalid size of picture!"<<endl;
        exit(0);
    }

    this->width=W;
    this->height=H;

    picture.resize(height,vector<pixels>(width)); // Resizing 2D vector

    for(int i=0;i<height;i++){ // Creating a white image
        for(int j=0;j<width;j++){
            picture[i][j].setR(255);
            picture[i][j].setG(255);
            picture[i][j].setB(255);
        }
    }
    maxValue=255;
}

ppmImage ppmImage::operator+(const ppmImage& oth){ // operator overloading for +

    if(this->width!=oth.width || this->height!=oth.height){ // If sizes are not equal return an empty object
        cerr<<"The sizes of ppm images are not equal!"<<endl;
        return ppmImage(this->width,this->height); // Returning an empty object 
    }

    ppmImage temp(width,height);
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            double r,g,b;

            r=picture[i][j].getR()+oth.picture[i][j].getR();
            g=picture[i][j].getG()+oth.picture[i][j].getG();
            b=picture[i][j].getB()+oth.picture[i][j].getB();

            if(r>255){r=255;} // Checking pixel values are greater than 255 or not
            if(g>255){g=255;}
            if(b>255){b=255;}
            temp.picture[i][j].setR(r);
            temp.picture[i][j].setG(g);
            temp.picture[i][j].setB(b);
        }
    }

    return temp;
}

ppmImage ppmImage::operator-(const ppmImage& oth){ // operator overloading for -

    if(this->width!=oth.width || this->height!=oth.height){ // Checking the sizes of images are equal or not
        cerr<<"The sizes of ppm images are not equal!"<<endl;
        return ppmImage(this->width,this->height);
    }

    ppmImage temp(width,height);

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            double r,g,b;

            r=picture[i][j].getR()-oth.picture[i][j].getR();
            g=picture[i][j].getG()-oth.picture[i][j].getG();
            b=picture[i][j].getB()-oth.picture[i][j].getB();

            if(r<0){r=0;}
            if(g<0){g=0;}
            if(b<0){b=0;}
            //cout<<r<<endl<<g<<endl<<b<<endl;
            temp.picture[i][j].setR(r);
            temp.picture[i][j].setG(g);
            temp.picture[i][j].setB(b);
        }
    }

    return temp;
}

ostream& operator<<(ostream& out,  ppmImage& obj){ // Basic operator << overload

    for(int i=0;i<obj.getH();i++){
        for(int j=0;j<obj.getW();j++){
            out<<obj.getPic()[i][j].getR()<<" "<<obj.getPic()[i][j].getG()<<" "<<obj.getPic()[i][j].getB()<<" ";
        }
        out<<endl;
    }
    
    return out;
}

int ppmImage::operator()(const int h, const int w, const int index)const{

    if(h<0 || h>height || w<0 || w>width){ // Checking invalid sizes
        return -1;
    }
    if(index<1 || index>3){ // Checking the point of red , gree, blue is valid or not
        return -1;
    }
    if(index==1){
        return picture[h][w].getR();
    }
    else if(index==2){
        return picture[h][w].getG();
    }

    return picture[h][w].getB();
}

void ppmImage::print()const{

    for(int i=0;i<height;i++){ // Basic nested loop
        for(int j=0;j<width;j++){
            cout<<picture[i][j].getR()<<" "<<picture[i][j].getG()<<" "<<picture[i][j].getB()<<" ";
        }
        cout<<endl;
    }

}


bool ppmImage::readPpmValues(){

    fstream file; // File which will be opened

    file.open(file_name,ios::in);

    if(!file.is_open()){ // Just printing unable to open error
        cerr<<"Unable to open file!"<<endl;
        return false;
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

    return true;
}

bool ppmImage::writePpmValues()const{

    fstream file; // Opening file to save ppm file

    file.open(file_name,ios::out);

    //cout<<"file name: "<<file_name<<endl;

    if(!file.is_open()){ // Just printing unable to open error
        cerr<<"Unable to open file!"<<endl; 
        return false;
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

    return true;
}

bool ppmImage::writePpmValues(const string f_name)const{

    fstream file; // Opening file to save ppm file

    file.open(f_name,ios::out);

    if(!file.is_open()){ // Just printing unable to open error
        cerr<<"Unable to open file!"<<endl; 
        return false;
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

    return true;
}

void ppmImage::scripts(){

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
    //print();
}


void ppmImage:: menu(){

    string choice;

    while(true){ // Main menu program

        cout<<"MAIN MENU"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<"1 - Open An ppmImage(D)"<<endl;
        cout<<"2 - Save ppmImage Data(D)"<<endl;
        cout<<"3 - Scripts(D)"<<endl;

        cin>>choice;

        if(choice=="0"){ // GOOD BYE
            exit(0);
        }
        else if(choice=="1"){ // OPTION1
            while(true){
                cout<<"0 - UP"<<endl;
                cout<<"1 - Enter The Name Of The ppmImage File"<<endl;
                cin>>choice;
                if(choice=="0")
                    break;
                else if(choice=="1"){
                    cin>>file_name;
                    readPpmValues();
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
                    writePpmValues();
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


int read_ppm(const string source_ppm_file_name, ppmImage& destination_object){

    destination_object.setName(source_ppm_file_name); // Setting file name to object
    

    return destination_object.readPpmValues() ? 1 : 0;
}

int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object){

    return source_object.writePpmValues(destination_ppm_file_name) ? 1 : 0;

}

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3){

    ppmImage img1(filename_image1); // Creating new object

    ppmImage img2(filename_image2); // Creating new object

    ppmImage img3(filename_image3); // Creating new object

    if(!img1.readPpmValues() || !img2.readPpmValues()){ // If object is not created return 0
        return 0;
    }

    img3=img1+img2;

    img3.setName(filename_image3);

    cout<<img3.getPic()[0][0].getR()<<endl;

    img3.writePpmValues(); // Writing values to txt
    
    return 1;
}

int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){

    ppmImage img1(filename_image1);

    ppmImage img2(filename_image2);

    ppmImage img3(filename_image3);

    if(!img1.readPpmValues() || !img2.readPpmValues()){ // Checking object are created
        return 0;
    }

    img3=img1-img2;

    img3.setName(filename_image3); // Setting file name
    cout<<img1.getPic()[0][0].getR()<<endl;
    cout<<img2.getPic()[0][0].getR()<<endl;
    cout<<img3.getPic()[0][0].getR()<<endl;

    img3.writePpmValues(); // Writing values to file
    
    return 1;
}

int test_print(const string filename_image1){

    ppmImage img1(filename_image1);

    if(!img1.readPpmValues()){
        return 0;
    }

    cout<<img1<<endl; // Test operator << overload

    return 1;
}


int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice){

    if(!(swap_choice==1 || swap_choice==2 || swap_choice==3)){
        return 0;
    }

    for(int i=0;i<image_object_to_be_modified.getH();i++){
        for(int j=0;j<image_object_to_be_modified.getW();j++){
            int temp;
            if(swap_choice==1){ // Swapping red and green with () function call operator
                temp=image_object_to_be_modified(i,j,1);
                image_object_to_be_modified.getPic()[i][j].setR(image_object_to_be_modified(i,j,2));
                image_object_to_be_modified.getPic()[i][j].setG(temp);
            }
            else if(swap_choice==2){ // Swapping red and blue with () function call operator
                temp=image_object_to_be_modified(i,j,1);
                //cout<<"before changing red: "<<image_object_to_be_modified.getPic()[i][j].getR()<<endl;
                //cout<<"before changing blue: "<<image_object_to_be_modified.getPic()[i][j].getB()<<endl;
                //cout<<"temp: "<<temp<<endl;
                //cout<<"image(i,j,3): "<<image_object_to_be_modified(i,j,3)<<endl;
                image_object_to_be_modified.getPic()[i][j].setR(image_object_to_be_modified(i,j,3));
                image_object_to_be_modified.getPic()[i][j].setB(temp);
                //cout<<"after changing red: "<<image_object_to_be_modified.getPic()[i][j].getR()<<endl;
                //cout<<"after changing blue: "<<image_object_to_be_modified.getPic()[i][j].getB()<<endl;
            }
            else{ // Swapping green and blue with () function call operator
                temp=image_object_to_be_modified(i,j,2);
                image_object_to_be_modified.getPic()[i][j].setG(image_object_to_be_modified(i,j,3));
                image_object_to_be_modified.getPic()[i][j].setB(temp);
            }
        }
    }  

    return 1;

}


ppmImage single_color(ppmImage& source, int color_choice){

    if(!(color_choice==1 || color_choice==2 || color_choice==3)){
        return ppmImage();
    }

    ppmImage temp(source.getW(),source.getH());

    for(int i=0;i<temp.getH();i++){
        for(int j=0;j<temp.getW();j++){
            if(color_choice==1){ // That means only red
                temp.getPic()[i][j].setR(source(i,j,1)); // Using () overload
                temp.getPic()[i][j].setG(0);
                temp.getPic()[i][j].setB(0);
                //cout<<"source: "<<source(i,j,1)<<"\ntemp: "<<temp.getPic()[i][j].getR()<<endl;
            }
            else if(color_choice==2){ // That means only green
                temp.getPic()[i][j].setR(0);
                temp.getPic()[i][j].setG(source(i,j,2)); // Using () overload
                temp.getPic()[i][j].setB(0);
            }
            else{ // That means only blue
                temp.getPic()[i][j].setR(0);
                temp.getPic()[i][j].setG(0);
                temp.getPic()[i][j].setB(source(i,j,3)); // Using () overload
            }
        }
    }

    return temp;
}





int main(){ // TEST MAIN

    string ppm_file_name1;
    string ppm_file_name2;
    string ppm_file_name3;

    int choice;

    
    cin>>ppm_file_name1;
    cin>>ppm_file_name2;
    cin>>ppm_file_name3;
    cin>>choice;

    if(choice==1){
        test_addition(ppm_file_name1,ppm_file_name2,ppm_file_name3);
    } 
    else if(choice==2){
        test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
    } 
    else if(choice==3){
        ppmImage img1;
        read_ppm(ppm_file_name1,img1);
        swap_channels(img1,2);
        write_ppm(ppm_file_name2,img1);
    } 
    else if(choice==4){
        ppmImage img1;
        read_ppm(ppm_file_name1,img1);
        swap_channels(img1,3);
        write_ppm(ppm_file_name2,img1);
    } 
    else if(choice==5){
        ppmImage img1;
        read_ppm(ppm_file_name1,img1);
        write_ppm(ppm_file_name2,single_color(img1,1));
    } 
    else if(choice==6){
        ppmImage img1;
        read_ppm(ppm_file_name1,img1);
        write_ppm(ppm_file_name2,single_color(img1,2));
    } 
    else if(choice==7){
        ppmImage img1;
        read_ppm(ppm_file_name1,img1);
        write_ppm(ppm_file_name2,single_color(img1,3));
    } 
    else{
        cerr<<"wrong choice!"<<endl;
    }

    

    return 0;
}