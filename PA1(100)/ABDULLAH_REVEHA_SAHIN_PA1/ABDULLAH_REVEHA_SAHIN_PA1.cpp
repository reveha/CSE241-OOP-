#include <iostream>
#include <string.h>


using namespace std;

const int MAX_DIGIT=9;

int valid (char *str){ // Checking -u input is valid or not

    int counter=0; // To count number of digits
    int arr2[MAX_DIGIT+1]; // To understande if there is a digit that used more than 1 times

    for(int i=0;i<MAX_DIGIT+1;i++){ // Filling my arrays to compare
        arr2[i]=0;
    }

    if(str[0]=='0'){ // Numbers cannot start with zero
        return -1;
    }
    
    for(int i=0;i<strlen(str);i++){
        
        if(!(str[i]<='9' && str[i]>='0')){ // Checking if there is an non number char ;           
            return 0; // FOR E2 CODE
        }
        else{
            counter++; // Counting my digits
        }
    }
    
    for(int i=0;i<strlen(str);i++){
        for(int j=0;j<MAX_DIGIT+1;j++){
            if(str[i]==j+'0'){ // If there is collusion increasing my array value
                arr2[j]++;
            }
        }
    }

    for(int i=0;i<MAX_DIGIT+1;i++){
        if(arr2[i]>1){ // That means if it is more than 1, it used at least 2 times This is error!
            return -1;
        }
    }

    if(counter>MAX_DIGIT || counter==0){ // that means Error
        return -1;
    }

    return 1;

}

bool check_number_valid(int secret){ // Checking  the random created secret number is valid or not in -r mode

    int arr[MAX_DIGIT+1];

    for(int i=0;i<MAX_DIGIT+1;i++){
        arr[i]=0;
    }

    while(secret>0){
        int mod=secret%10;
        secret/=10;
        for(int i=0;i<=MAX_DIGIT;i++){ // I increased index of number in arr[] array
            if(mod==i){
                arr[i]++;
            } 
        }
    }

    for(int i=0;i<MAX_DIGIT+1;i++){ // And i am checking if there is more than 1 a number return false;
        if(arr[i]>1){
            return false;
        }
    }

    return true;
}

int pow(int p){ // Taking power for 10^n;

    int number=1;

    for(int i=0;i<p-1;i++){ // Taking 10 to p power in this function
        number*=10;
    }

    return number;
}


void convert_to_array(int secret, char *ch_array){
    // Converting the int to char array to use in game;
    
    int temp=secret;
    int counter=0;

    while(temp>0){ // Counting number of digit of secret number
        temp/=10;
        counter++;
    }
    temp=secret;

    
    for(int i=counter-1;i>-1;i--){ // Converting int to char array
        int mod=temp%10;
        temp/=10;
        ch_array[i]='0'+mod;
        
    }

}



int check_equal(string str, char *secret_arr){ // This function to check user input and secret number

    if(str[0]=='0' || str[0]=='-'){
        return 0;
    }

    if(str.length()!=strlen(secret_arr)){ // Checking E1 Error code
        return -1;
    }

    for(int i=0;i<str.length();i++){ // Checking E2 Error code
        if(!(str[i]<='9' && str[i]>='0')){
            return -2;
        }
    }

    for(int i=0;i<str.length();i++){ // Checking if there are  a number more than 1
        for(int j=0;j<str.length();j++){
            if(str[i]==str[j] && i!=j){ // That if means there is at least a number more than 1 times
                return 0;
            }
        }
    }

    return 1;
}

void game(char *secret_arr){ // My game function 

    int C_exact=0; // To count exact values
    int C_misplaced=0; // To count misplaced values 
    int iterations=0; // To count iterations 

    string user_input; // To get user value to compare
 
    while(true){

        if(iterations==100){ // That means end of the game
            cout<<"FAILED"<<endl;
            exit(0);
        }

        C_exact=0; // I need to make zero exact and misplaced values every raund
        C_misplaced=0;

        cin>>user_input; // I got user input

        iterations++;

        if(check_equal(user_input,secret_arr)==-1){ // ERROR MESSAGES
        
            cerr<<"E1"<<endl;
            exit(0);
        }
        else if(check_equal(user_input,secret_arr)==0){ // ERROR MESSAGES
            cerr<<"E0"<<endl;
            exit(0);
        }
        else if(check_equal(user_input,secret_arr)==-2){ // ERROR MESSAGES
            cerr<<"E2"<<endl;
            
        }
        else{
            for(int i=0;i<user_input.length();i++){ // Counting c_exact 
                if(user_input[i]==secret_arr[i]){
                    C_exact++;
                }
            }

            for(int i=0;i<user_input.length();i++){ // Counting c_misplaced
                for(int j=0;j<strlen(secret_arr);j++){
                    if(secret_arr[i]==user_input[j] && i!=j){
                        C_misplaced++;
                    }
                }
            }
            if(C_misplaced==0 && C_exact==user_input.length()){ // The user won
                cout<<"FOUND "<<iterations<<endl;
                exit(0);
            }
            cout<<C_exact<<" "<<C_misplaced<<endl;
        }

        
        
    }


}

int main(int argc, char *argv[]){
    
    srand(time(NULL));

    int secret_number;

    if(argv[1][1]=='r'){ // Checking the user entered word -r or -u
        if(!(argv[argc-1][0]>'0' && argv[argc-1][0]<='9') || strlen(argc[argv-1])!=1){ // Checking valid input or not
            cerr<<"E0!";
            exit(0);
        }
        while(true){
            secret_number=(rand()%(pow((argc[argv-1][0]-'0'))*9)+pow((argc[argv-1][0]-'0'))); // Creating random number
            if(check_number_valid(secret_number)){
                break;
            }
        }

        char *secret_arr=new char[argv[argc-1][0]-'0'];
        //char secret_arr2[argv[argc-1][0]-'0'];

        convert_to_array(secret_number,secret_arr); // Converting int secret number to char array to compare them

        //cout<<strlen(secret_arr)<<" "<<strlen(secret_arr2)<<endl;
        game(secret_arr);
        
    } 
    else if(argv[1][1]=='u'){ // Checking the user entered word -r or -u

        if(valid(argv[argc-1])==-1){ // Checking valid input or not
            cerr<<"E0"<<endl;
            exit(0);
        }
        else if(valid(argv[argc-1])==0){ // Checking valid input or not
            cerr<<"E2"<<endl;
            exit(0);
        }
        game(argv[argc-1]);

    }
    else{
        cerr<<"E0"<<endl;
        exit(0);
    }

    return 0;
}



