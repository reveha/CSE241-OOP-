/**
 *
 * @author abdullah reveha
 */

import java.util.ArrayList;

public class Dataset{
    
    private ArrayList<BaseClassObjects> objectList; // To keep objects
    private ArrayList<Observer> observerList; // To keep Player and Viewer objects


    public Dataset(ArrayList<BaseClassObjects> objectList, ArrayList<Observer> observerList){ // Constructor
        this.objectList = objectList;
        this.observerList = observerList;
    }
    
    public Dataset(){ // No parameter constructor
        objectList=new ArrayList<>();
        observerList=new ArrayList<>();
    }
    
    public void print(){
        for(BaseClassObjects abc: objectList){
            System.out.println(abc.getObjectName());
        }
    }
    
    public void notifyObservers(BaseClassObjects obj){ // To add object to Player or Viewer's ArrayList
        for(Observer observer : observerList){// Range based for loop
            observer.add(obj);
        }
    }
    
    public void unNotifyObservers(BaseClassObjects obj){ // To delete object to Player or Viewer's ArrayList
        for(Observer observer : observerList){ // Range based for loop
            //System.out.println("abc: "+obj.getObjectName());
            observer.delete(obj);
        }
    }
    
    public void add(BaseClassObjects obj){ // To add object to BaseClassObjects ArrayList
        if(!objectList.contains(obj)){ // Checking if exist or not before
            objectList.add(obj);
            notifyObservers(obj);
        }
    }
    
    public void delete(BaseClassObjects obj){ // To delete object to BaseClassObjects ArrayList
            objectList.remove(obj);
            unNotifyObservers(obj);
        
    }
    
    public void register(Observer obj){ // Register for Playable or Viewer class
        if(!observerList.contains(obj)){ // Checking if exist or not before
            observerList.add(obj);
            
        }
    }
    
    public void remove(Observer obj){ // Unregister for Playable or Viewer class
            observerList.remove(obj);
        
    }
}
