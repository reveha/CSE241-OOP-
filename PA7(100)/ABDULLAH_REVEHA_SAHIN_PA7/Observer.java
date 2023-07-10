/**
 *
 * @author abdullah reveha
 */
public interface Observer{ // Interface to use Player and Viewer class
    
    public void add(BaseClassObjects obj);
    
    public void delete(BaseClassObjects obj);
    
    public void next(String type);
    
    public void previous(String type);
    
    public void show_list();
    
}
