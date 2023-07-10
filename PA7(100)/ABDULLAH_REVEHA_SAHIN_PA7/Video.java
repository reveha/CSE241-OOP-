/**
 *
 * @author abdullah reveha
 */
public class Video extends BaseClassObjects implements Visual, Playable{
    private String duration;
    private String type_of_video;

    public Video(String objectName, String duration, String other_info) { // Constructor
        super(objectName); // Calling the base class constructor
        this.duration = duration;
        this.type_of_video = other_info;
    }

    

    @Override
    public void play(){ // Printing the now playing!
        System.out.println("Playing video: " + getObjectName());
        System.out.println("Duration: " + this.duration);
        System.out.println("Other info(Type of Video): " + this.type_of_video);
    }
    
    @Override
    public void display(){ // Calling the play method
       play();
    }
    
    @Override
    public String getName(){ // Override method for interface to get Name of object
        return super.getObjectName();
    }
    
    @Override
    public void info(){ // Printing informations
        System.out.println("Video: " + getObjectName());
        System.out.println("Duration: " + this.duration);
        System.out.println("Other info: " + this.type_of_video);
    }
}
