/**
 *
 * @author abdullah reveha
 */
public interface Playable {
    public void play();
    
    default String getName(){ // This method is used to get Name of Objects in the Player class
        return null;
        // I did it default not to have to create every class which implements Playable interface
    }
    default void info(){ 
        // I did it default not to have to create every class which implements Playable interface
        
    }
}
