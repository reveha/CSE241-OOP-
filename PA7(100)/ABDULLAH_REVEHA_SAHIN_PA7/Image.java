/**
 *
 * @author abdullah reveha
 */
public class Image extends BaseClassObjects implements Visual, Non_playable{
    private String dimension;
    private String topic;

    public Image(String objectName, String dimension, String other_info){ // Constructor
        super(objectName); // Calling the base class constructor
        this.dimension = dimension;
        this.topic = other_info;
    }

    @Override
    public void display(){ // Displaying the information
        System.out.println("Displaying image: " + getObjectName());
        System.out.println("Dimension: " + this.dimension);
        System.out.println("Other info(Topic): " + this.topic);
    }

    @Override
    public void draw(){
        display();
    }
    
    @Override
    public String getName(){ // Override method to get name of object
        return super.getObjectName();
    }
    
    @Override
    public void info(){ // Printing the information
        System.out.println("Image: " + getObjectName());
        System.out.println("Dimension: " + this.dimension);
        System.out.println("Other info: " + this.topic);
    }
    
    
}
