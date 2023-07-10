
/**
 *
 * @author abdullah reveha
 */
public class TestClass {
    public static void main(String arg[]){
        Dataset ds=new Dataset();
        
        Player p1=new Player();
        Player p2=new Player();
        
        Viewer v1=new Viewer();
        Viewer v2=new Viewer();
        
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
        
        Image img1=new Image("imagename1", "dimension info1", "Happiness");
        Image img2=new Image("imagename2", "dimension info2", "War");
        Image img3=new Image("imagename3", "dimension info3", "Sad");
        Image img4=new Image("imagename4", "dimension info4", "Crazy");
        Image img5=new Image("imagename5", "dimension info5", "Tree");
        
        Audio au1=new Audio("audioname1", "duration1", "Music");
        Audio au2=new Audio("audioname2", "duration2", "Radio");
        Audio au3=new Audio("audioname3", "duration3", "PodCast");
        
        Video vid1=new Video("videoname1", "duration1", "TV Series");
        Video vid2=new Video("videoname2", "duration2", "Youtube Video");
        Video vid3=new Video("videoname3", "duration3", "Film");
        
        Text tx1=new Text("textname1", "Turkish");
        Text tx2=new Text("textname2", "English");
        Text tx3=new Text("textname3", "Spanish");
        
        //Here we create different objects. 
        ds.add(img1);
        ds.add(img2); 
        ds.add(img3);
        ds.add(img4);
        ds.add(img5); 
        
        ds.add(au1); 
        ds.add(au2); 
        ds.add(au3);
        
        ds.add(vid1);
        ds.add(vid2);
        ds.add(vid3);
        
        ds.add(tx1); 
        ds.add(tx2);
        ds.add(tx3);
        System.out.println("After added items: ");
        ds.print();
        
        Playable po=p1.currently_playing();
        System.out.println("\n<Playable> po playing currently playing: ");
        po.info();
        System.out.println();
        
        Non_playable np=v1.currently_viewing();
        System.out.println("\n<Non_playable> po showing currently showing: ");
        np.info();
        System.out.println();
        
        System.out.println("\nScanning next audio for p1 player: ");
        p1.next("audio");
        p1.next("audio");
        p1.next("audio");
        p1.next("audio");
        p1.next("audio");
        System.out.println("\nTesting the invalid index of ArrayList: ");
        p1.next("audio");
        
        System.out.println();
        
        System.out.println("\nScanning next text for v1 player: ");
        v1.next("text");
        System.out.println();
        
        System.out.println("\nScanning previous text for v1 player: ");
        v1.previous("image");
        System.out.println();
        
        System.out.println("\np1.show_list(): ");
        p1.show_list();
        
        System.out.println("\nv1.show_list(): ");
        v1.show_list();
        
        System.out.println("\nDeleting video2 from dataset: ");
        ds.delete(vid2);
        
        System.out.println("\np1 player, After deleted video2 from the dataset: ");
        p1.show_list();
        System.out.println("\np2 player, After deleted video2 from the dataset: ");
        p2.show_list();
        System.out.println("\nDataset, After deleted video2 from dataset: ");
        ds.print();
        

    }
}
