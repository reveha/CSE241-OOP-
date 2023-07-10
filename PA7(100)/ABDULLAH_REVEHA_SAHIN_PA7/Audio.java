/**
 *
 * @author abdullah reveha
 */
public class Audio extends BaseClassObjects implements NonVisual, Playable{
    private String duration; // To keep duration info
    private String type_of_sound;

    public Audio(String objectName, String duration, String other_info){ // Constructor
        super(objectName); // Calling base class constructor
        this.duration = duration;
        this.type_of_sound = other_info;
    }

    
    @Override
    public void play(){ // Implements the interface method to play Audio
        System.out.println("Playing audio: " + getObjectName());
        System.out.println("Duration: " + this.duration);
        System.out.println("Other info(Type of Sound): " + this.type_of_sound);
    }
    
    @Override
    public void show(){ // Implements the interface method to call play method
        play();
    }
    
    @Override
    public String getName(){ // Implement the interface method to get name
        return super.getObjectName();
    }
    
    @Override
    public void info(){ // Info method prints the information about this Audio
        System.out.println("Audio: " + getObjectName());
        System.out.println("Duration: " + this.duration);
        System.out.println("Other info: " + this.type_of_sound);
    }
    
    
}
