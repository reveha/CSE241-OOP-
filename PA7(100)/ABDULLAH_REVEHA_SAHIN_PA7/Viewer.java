/**
 *
 * @author abdullah reveha
 */

import java.util.ArrayList;

public class Viewer implements Observer, Non_playable{
    private ArrayList<Non_playable> list; // To keep Non_playable objects
    private int currentPlayingIndex; // currentPlayingIndex

    public Viewer(){
        list=new ArrayList<>();
        this.currentPlayingIndex=0;
    }

    public Viewer(int currentPlayingIndex){
        this.currentPlayingIndex = currentPlayingIndex;
        this.currentPlayingIndex=0;
    }

    public Viewer(ArrayList<Non_playable> list, int currentPlayingIndex){
        this.list = list;
        this.currentPlayingIndex = currentPlayingIndex;
    }
    
    public ArrayList<Non_playable> getList(){
        return this.list;
    }
    
    @Override
    public void delete(BaseClassObjects obj){
        if(obj instanceof Non_playable){ // Deleting an object from the ArrayList
            // Checking the object is Playable or not and ArrayList has it to delete
            list.remove(obj); // Type casting
        }
    }
        
    
    @Override
    public void add(BaseClassObjects obj) {
        if(obj instanceof Non_playable){
            // Checking the object is Playable or not and ArrayList has it to add
            list.add((Non_playable) obj);
        }
    }

    @Override
    public void draw(){
        try{ // SIMPLE TRY CATCH TO CHECK LIST IS EMPTY OR NOT
            if(list.isEmpty()){
                throw new EmptyListException("No playable objects in the playlist.");
            }
        }catch(EmptyListException ex){
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
        
        System.out.println("Currently showing: " + this.list.get(currentPlayingIndex).getName());
        this.list.get(currentPlayingIndex).draw();
    }
    
    @Override
    public void next(String type){ // To search next and play
        boolean check=false; // To understand there is or not the type of object for next method!
        try{ // Simple try-catch to catch empty ArrayList
            if(list.isEmpty()){ // If the ArrayList is empty throw and EmptyListException 
                throw new EmptyListException("No showable object in the list!");
            }
            
        }catch(EmptyListException ex){
            // Catching the EmptyListException!
            ex.printStackTrace();
        }
         
        currentPlayingIndex++;  // Increasing the index number of Player.
        
        try{ // Simple try-catch to catch Invalid size of ArrayList
            if(currentPlayingIndex>=list.size()){
                // If the index is greater or equal than size of ArrayList throw an InvalidIndexException
                throw new InvalidIndexException("Invalid index in the list!");
            }
        }catch(InvalidIndexException ex){
            // Catching the InvalidIndexException
            ex.printStackTrace();
            currentPlayingIndex=0;
            System.out.println("List is ended! Started again to search!!");
        }
        // Catching the InvalidIndexException
        for(int i=currentPlayingIndex;i<list.size();i++){
            if("text".equals(type)){ // If the type is Text
                if(list.get(i) instanceof Text){ // Checking the instanceof Text for every index of ArrayList
                    currentPlayingIndex=i; // Now playing index 'i';
                    check=true; // We found
                    System.out.println("Showing next "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
            else if("image".equals(type)){  // If the type is Image
                if(list.get(i) instanceof Image){ // Checking the instanceof Image for every index of ArrayList
                    currentPlayingIndex=i; // Now playing index 'i';
                    check=true; // We found
                    System.out.println("Drawing next "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
        }
        
        if(check){
            // If we found show the index of Non_playable
            list.get(currentPlayingIndex).draw();
        }
        else{ // Print error message
            System.out.println("There is no media for title \""+type+"\"");
        }
    }
    
    @Override
    public void show_list(){
        for(Non_playable i: list){
            System.out.println(i.getName());
        }
    }
    
    @Override
    public void previous(String type){ // Same algortihm with Player previous
        boolean check=false;
        try{
            if(list.isEmpty()){
                throw new EmptyListException("No playable object in the list!");
            }
            
        }catch(EmptyListException ex){
            ex.printStackTrace();
        }
        
        currentPlayingIndex--;
        try{
            if(currentPlayingIndex<0){
                throw new InvalidIndexException("Invalid index in the list!");
            }
        }catch(InvalidIndexException ex){
            ex.printStackTrace();
            currentPlayingIndex=list.size();
            System.out.println("List is ended! Started again to search!!");
        }
        for(int i=currentPlayingIndex;i>0;i--){
            if("text".equals(type)){
                if(list.get(i) instanceof Text){
                    currentPlayingIndex=i;
                    check=true;
                    System.out.println("Showing previous "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
            else if("image".equals(type)){
                if(list.get(i) instanceof Image){
                    currentPlayingIndex=i;
                    check=true;
                    System.out.println("Drawing previous "+type+" "+list.get(currentPlayingIndex).getName());
                    break;
                }
            }
        }
        
        if(check){
            list.get(currentPlayingIndex).draw();
        }
        else{
            System.out.println("There is no media for title \""+type+"\"");
        }
    }
    
    public Non_playable currently_viewing(){
        return list.get(currentPlayingIndex);
    }
    
}
