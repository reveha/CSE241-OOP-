import java.util.Scanner;

public class driver2{
    public static void main(String arg[]){
        /*
    driver code ;
    */
    Scanner scn=new Scanner(System.in);
    Tetromino.Tetros tetros=Tetromino.Tetros.shape_I;
    System.out.print("How many times you want to move TO RIGHT:");
    int move_count=scn.nextInt();
    System.out.print("How many times you want to rotate TO RIGHT:");
    int rotate_count=scn.nextInt();
    Tetromino t2=new Tetromino(tetros.shape_J);
    Tetromino t3=new Tetromino(tetros.shape_I);
    Tetromino t4=new Tetromino(tetros.shape_T);
    Tetromino t5=new Tetromino(tetros.shape_O);
    Tetromino t6=new Tetromino(tetros.shape_S);
    Tetromino t7=new Tetromino(tetros.shape_Z);
    Tetromino t8=new Tetromino(tetros.shape_L);
    Tetris t1=new Tetris(10,15);

    t1.Add(t2);// ADDING THE TOP BOTTOM

    t1.Animate(t2,move_count,rotate_count,"R"); // every member function is called from Animate function

    System.out.print("How many times you want to move TO LEFT:");
    move_count=scn.nextInt();
    System.out.print("How many times you want to rotate TO LEFT:");
    rotate_count=scn.nextInt();;
    rotate_count%=4;
    rotate_count=4-rotate_count;
    t1.Animate(t4,move_count,rotate_count,"L");
    t1.Add(t7);
    t1.check_index(t7,(int)(Math.random()*7),"L");
    t1.fill_indexes(t7);
    t1.clear_top(t7);
    t1.draw();
    t1.driver_test();
    t1.draw();
    System.out.println("\n'A' WILL BE DELETED TO SHOW clear() FUNCTION IS WORKING");
    t1.clear();
    t1.draw();
    System.out.println("\nAFTER CLEAR FUNCTION WORKED");
    }
}