import java.util.Scanner;

public class driver1{
    public static void main(String arg[]){
        Scanner scn=new Scanner(System.in);
        String ch="a",rotate_direction,move_direction;
        int height,length,count_rotate,count_move,number=-1;
        System.out.println("Enter the size of the board (height-length)\n");
        height=scn.nextInt();
        length=scn.nextInt();
        Tetris t1=new Tetris(height,length);
        Tetromino.Tetros tetros=Tetromino.Tetros.shape_I;
        System.out.print("\033[H\033[2J");
        t1.draw();
        while(!ch.equals("Q")){ // while loop until board is full or press 'Q';
            System.out.print("\nEnter the shape (R FOR RANDOM) or 'Q' to exit (I,O,T,L,J,S,Z): ");
            ch=scn.next();
            if(ch.equals("R")){
                number=(int)(Math.random()*7);// according to the number choosing randomly
                //cout<<number;
            }
            if((ch.equals("I")||ch.equals("O")||ch.equals("T")||ch.equals("L")||ch.equals("J")||ch.equals("S")||ch.equals("Z")||ch.equals("R"))){
                if(ch.equals("I")||number==0){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_I);
                    t1.Add(t);
                }
                else if(ch.equals("O")||number==1){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_O);
                    t1.Add(t);
                }
                else if(ch.equals("T")||number==2){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_T);
                    t1.Add(t);
                }
                else if(ch.equals("L")||number==3){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_L);
                    t1.Add(t);
                }
                else if(ch.equals("J")||number==4){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_J);
                    t1.Add(t);
                }
                else if(ch.equals("S")||number==5){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_S);
                    t1.Add(t);
                }
                else if(ch.equals("Z")||number==6){// to add tetromino top bottom
                    Tetromino t=new Tetromino(tetros.shape_Z);
                    t1.Add(t);
                }
                //these while loops are to ask question to user.
                do{
                    System.out.print("Enter the rotate direction of the shape(R->right && L->left): ");
                    rotate_direction=scn.next();
                    if(rotate_direction.equals("R")||rotate_direction.equals("L")){
                        break;
                    }
                    System.err.println("Enter just 'R' or 'L'");
                }while(true);
                do{
                    System.out.print("Enter the how many times will be rotated the shape: ");
                    count_rotate=scn.nextInt();
                    if(count_rotate<0){
                        System.err.println("Number of rotation cannot be negative");
                    }
                }while(count_rotate<0);
                do{
                    System.out.print("Enter the moving direction of the shape(R->right && L->left): ");
                    move_direction=scn.next();
                    if(move_direction.equals("R")||move_direction.equals("L")){
                        break;
                    }
                    System.err.println("Enter just 'R' or 'L'");
                }while(true);
                do{
                    System.out.print("Enter the how many times will be moved the shape: ");
                    count_move=scn.nextInt();
                    if(count_move<0){
                        System.err.println("Number of moving counter cannot be negative");
                    }
                }while(count_move<0);

                count_rotate%=4;// each 4 rotation it become same shape; so i took the modula of the number of rotation
            
                if(rotate_direction.equals("L")){count_rotate=4-count_rotate;
                    if(count_rotate==4){count_rotate=0;}// when it rotates 4 times it become original shape  
                } // my rotate function rotates to right 
        //if the user enter left, i will rotate 4-count_rotate times to rigth instead of count_rotate times to left
                
                if(ch.equals("I")||number==0){
                    Tetromino t=new Tetromino(tetros.shape_I);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }
                    
                }
                else if(ch.equals("O")||number==1){
                    Tetromino t=new Tetromino(tetros.shape_O);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }  
                }
                else if(ch.equals("T")||number==2){
                    Tetromino t=new Tetromino(tetros.shape_T);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }  
                }
                else if(ch.equals("L")||number==3){
                    Tetromino t=new Tetromino(tetros.shape_L);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }  
                }
                else if(ch.equals("J")||number==4){
                    Tetromino t=new Tetromino(tetros.shape_J);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }  
                }
                else if(ch.equals("S")||number==5){
                    Tetromino t=new Tetromino(tetros.shape_S);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }
                }
                else if(ch.equals("Z")||number==6){
                    Tetromino t=new Tetromino(tetros.shape_Z);
                    if(t1.game_over()){
                        t1.Animate(t,count_move,count_rotate,move_direction);
                    }  
                }
            }
            
            else if(ch.equals("Q")){
                System.out.println("Good bye");
            }
            else{
                System.err.println("You typed incorrectly");
            }
            if(!t1.game_over()){
                System.out.println("The board is fulled.");
                break;
            }
            number=-1;
        }
    }
}