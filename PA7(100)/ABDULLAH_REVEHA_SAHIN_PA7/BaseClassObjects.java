/**
 *
 * @author abdullah reveha
 */
public abstract class BaseClassObjects{ // Base class to use inheritence
    
    private String objectName;
    
    public BaseClassObjects(String objectName){
        this.objectName=objectName;
    }

    public String getObjectName(){
        return objectName;
    }

    public void setObjectName(String objectName){
        this.objectName = objectName;
    }
    
}
