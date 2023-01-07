/** Demo program for OOP Lecture Programming Assignment 6 */
public class Demo {
    public static void main(String[] args) {
        Dataset ds = new Dataset();

        // Add some Player observer
        Player p1 = new Player();
        Player p2 = new Player();


        // Add some Viewer observer
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();


        // Register observers to Ds
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);


        // Create some Entry.
        ds.add(new Image("image1", "400x300", "A mountain image."));
        ds.add(new Image("image2", "400x600", "A tree image."));
        ds.add(new Image("image3", "500x600", "A mountain image."));
        ds.add(new Image("image4", "1920x1080", "A mountain image."));


        ds.add(new Audio("audio1",36.2 , "OOP Lecture 1"));
        ds.add(new Audio("audio2", 45.2, "OOP Lecture 2"));
        ds.add(new Audio("audio3", 56.4, "OOP Lecture 3"));


        ds.add(new Video("video1", 43.14, "400x500", "OOP Lecture 4"));
        ds.add(new Video("video2", 45.14, "400x500", "OOP Lecture 5"));
        ds.add(new Video("video3", 35.14, "400x500", "OOP Lecture 6"));

        ds.add(new Text("text1", "Quiz 1"));
        ds.add(new Text("text2", "Quiz 2"));
        ds.add(new Text("text3", "Quiz 3"));

        // Get currently playing object and print information.
        Playable po = p1.getCurrentlyPlaying();
        System.out.println("Currently playing object of p1: ");
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }

        System.out.println();
        System.out.println();
        System.out.println();

        // Go next Video type, get that object and print information.
        p1.next("Video");
        System.out.println("Currently playing object of p1 after next: ");
        po = p1.getCurrentlyPlaying();
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }


        // Show list of Player 1
        System.out.println();
        System.out.println();
        System.out.println("Player 1 show list:");
        System.out.println("-------------------");
        p1.showList();
        System.out.println("-------------------");


        // Get currently playing object and print information.
        po = p1.getCurrentlyPlaying();
        System.out.println("Information of po ");
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }

        // Remove currently playing object from dataset.
        ds.remove(po);

        // Show list of p1 again.
        System.out.println();
        System.out.println();
        System.out.println("Player 1 show list:");
        System.out.println("-------------------");
        p1.showList();
        System.out.println("-------------------");


        // get new currently playing object to check that
        // its automatically go next object when current playing object
        // is deleted.
        System.out.println();
        System.out.println();
        System.out.println();
        po = p1.getCurrentlyPlaying();
        System.out.println("Information of po ");
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }

        System.out.println();
        System.out.println();
        System.out.println();

        // Go next object which is Video type.
        // And print information of currently playing.
        p1.next("Video");
        po = p1.getCurrentlyPlaying();
        System.out.println("Currently playing of p1: ");
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }

        System.out.println();
        System.out.println();
        System.out.println();

        // Go next object again.
        // And print information of currently playing.
        p1.next("Video");
        po = p1.getCurrentlyPlaying();
        System.out.println("Next is: ");
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }


        System.out.println();
        System.out.println();
        System.out.println();

        // Get currently viewing object from v1 as NonPlayable type.
        // And print information of currently viewing.
        NonPlayable nonPlayable = (NonPlayable) v1.getCurrentlyViewing();
        System.out.println("NonPlayable currently viewing of v1: ");
        if (nonPlayable == null){
            System.out.println("There is no currently viewing object for v1");
        } else {
            nonPlayable.informationOfNonPlayable();
        }


        // Show list of v1
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println("v1 show list:");
        System.out.println("------------");
        v1.showList();
        System.out.println("------------");



        // Go previous object.
        // And print information of currently playing.
        System.out.println();
        System.out.println();
        System.out.println();
        p1.previous("Video");
        po = p1.getCurrentlyPlaying();
        System.out.println("Previous is: ");
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }


        System.out.println();
        System.out.println();
        System.out.println();



        // Unregister p1.
        ds.unregister(p1);

        // Get currently playing object of p1.
        // p1 is unregistered so po has to be null.
        po = p1.getCurrentlyPlaying();
        if (po == null){
            System.out.println("There is no currently playing object for p1");
        } else {
            po.informationOfPlayable();
        }


    }
}
