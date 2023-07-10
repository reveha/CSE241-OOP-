/**
 *
 * @author abdullah reveha
 */

import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Player implements Observer, Playable{
    private ArrayList<Playable> list; // To keep Playable objects
    private int currentPlayingIndex; // currentPlayingIndex

    public Player(ArrayList<Playable> list, int currentPlayingIndex){ // Constructor
        this.list = list;
        this.currentPlayingIndex = currentPlayingIndex;
        
    }

    public Player(int currentPlayingIndex){ // Constructor
        list=new ArrayList<>();
        this.currentPlayingIndex = currentPlayingIndex;
        this.currentPlayingIndex=0;
    }

    public Player(){ // No parameter constructor
        list=new ArrayList<>();
        this.currentPlayingIndex=0;
    }
    
    @Override
    public void show_list(){ // Printing the list of playable object
        for(Playable i: list){
            System.out.println(i.getName());
        }
    }
    
    public ArrayList<Playable> getList(){ // Getter for ArrayList
        return this.list;
    }
    
    @Override
    public void delete(BaseClassObjects obj){ // Deleting an object from the ArrayList
        if(obj instanceof Playable){ 
            // Checking the object is Playable or not and ArrayList has it to delete
            list.remove(obj); // Type casting
        }
    }
    
    @Override
    public void add(BaseClassObjects obj){
        if(obj instanceof Playable && !list.contains(obj)){
            // Checking the object is Playable or not and ArrayList has it to add
            list.add((Playable) obj);
        }
    }
    
    public void next(String type){ // To search next and play
        boolean check=false; // To understand there is or not the type of object for next method!
        try{ // Simple try-catch to catch empty ArrayList
            if(list.isEmpty()){ // If the ArrayList is empty throw and EmptyListException 
                throw new EmptyListException("No playable object in the list!");
            }
            
        }catch(EmptyListException ex){
            // Catching the EmptyListException!
            ex.printStackTrace();
        }
        
        currentPlayingIndex++; // Increasing the index number of Player.
        
        try{ // Simple try-catch to catch Invalid size of ArrayList
            if(currentPlayingIndex>=list.size()){ 
                // If the index is greater or equal than size of ArrayList throw an InvalidIndexException
                throw new InvalidIndexException("Invalid index in the list!");
            }
        }catch(InvalidIndexException ex){
            // Catching the InvalidIndexException
            ex.printStackTrace();
            currentPlayingIndex=0; // Resetting the index of player
            System.out.println("\nList is ended! Started again to search!!\n"); // Printing error message
        }
        for(int i=currentPlayingIndex;i<list.size();i++){
            if("video".equals(type)){ // If type is VIDEO
                //System.out.println("nmerhaba");
                if(list.get(i) instanceof Video){ // Checking the instanceof Video for every index of ArrayList
                    currentPlayingIndex=i; // Now playing index 'i';
                    check=true; // We found
                    System.out.println("Playing next "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
            else if("audio".equals(type)){ // If the type is AUDIO
                if(list.get(i) instanceof Audio){ // Checking the instanceof Audio for every index of ArrayList
                    currentPlayingIndex=i; // Now playing index 'i';
                    check=true; // We found
                    System.out.println("Playing next "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
        }
        
        if(check){
            // If we found play the index of Playable
            list.get(currentPlayingIndex).play();
        }
        else{ // Print error message
            System.out.println("There is no media for title \""+type+"\"");
        }
    }
    
    public void previous(String type){
        boolean check=false;
        
        try{ // Simple try-catch to catch empty ArrayList
            if(list.isEmpty()){
                throw new EmptyListException("No playable object in the list!");
            }
            
        }catch(EmptyListException ex){
            ex.printStackTrace();
        }
        
        currentPlayingIndex--;
        
        try{// Simple try-catch to catch Invalid size of ArrayList
            if(currentPlayingIndex<0){
                throw new InvalidIndexException("Invalid index in the list!");
            }
        }catch(InvalidIndexException ex){
            ex.printStackTrace();
            currentPlayingIndex=list.size(); // Resetting the index of player
            System.out.println("List is ended! Started again to search!!");
        }
        for(int i=currentPlayingIndex;i>0;i--){
            if("video".equals(type)){
                if(list.get(i) instanceof Video){ // Checking the instanceof Video for every index of ArrayList
                    currentPlayingIndex=i; // Now playing index 'i';
                    check=true; // We found
                    System.out.println("Playing previous "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
            else if("audio".equals(type)){
                
                if(list.get(i) instanceof Audio){ // Checking the instanceof Audio for every index of ArrayList
                    currentPlayingIndex=i; // Now playing index 'i';
                    check=true; // We found
                    System.out.println("Playing previous "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
        }
        
        if(check){ // If we found play the index of Media
            list.get(currentPlayingIndex).play();
        }
        else{ // Print error message
            System.out.println("There is no media for title \""+type+"\"");
        }
    }
    
    

    

    @Override
    public void play(){ // This method just currentlyIndex playing
        try{ // Simple try-catch to catch empty ArrayList
            if(list.isEmpty()){
                throw new EmptyListException("No playable objects in the playlist.");
            }
        }catch(EmptyListException ex) {
            ex.printStackTrace();
        }
        
        
        try{ // Simple try-catch to catch invalid index of ArrayLis
            if(currentPlayingIndex<0 || currentPlayingIndex>=list.size()){
                throw new InvalidIndexException("Invalid index in the list!");
            }
        }catch(InvalidIndexException ex){
            currentPlayingIndex=0;
            ex.printStackTrace();
        }
        
        // Playing the current audio or music
        System.out.println("Currently playing: " + list.get(currentPlayingIndex).getName());
        list.get(currentPlayingIndex).play();
        
    }
    
    public Playable currently_playing(){
        return list.get(currentPlayingIndex);
    }

    

 
    
}
