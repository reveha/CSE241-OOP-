/**
 *
 * @author abdullah reveha
 */
public class Text extends BaseClassObjects implements NonVisual, Non_playable{
    private String language;

    public Text(String objectName, String other_info){ // Constructor
        super(objectName); // Calling the base class constructor
        this.language = other_info;
    }

    @Override
    public void show() {
        System.out.println("Showing text: " + getObjectName());
        System.out.println("Other info(Language): " + this.language);
    }
    
    @Override
    public void draw() {
        show();
    }
    
    @Override
    public String getName(){
        return super.getObjectName();
    }
    
    
    @Override
    public void info(){
        System.out.println("Text: " + getObjectName());
        System.out.println("Other info: " + this.language);
    }
    
}
