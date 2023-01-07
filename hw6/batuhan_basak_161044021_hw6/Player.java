import java.util.ArrayList;
import java.util.List;

/** Player class */
public class Player implements Observer{

    /** This is the Playable object that is currently viewed by Player */
    private Playable currentlyPlaying;

    /** Play list. */
    private List<Playable> playList = new ArrayList<Playable>();

    /** Getter method for currentlyPlaying object
     *
     * @return currently playing object.
     */
    public Playable getCurrentlyPlaying(){
        return currentlyPlaying;
    }

    /** Show all playlist */
    public void showList(){
        for (Playable p : playList){
            p.informationOfPlayable();
        }
    }

    /** Updates play list respect to updated list
     *
     * @param updatedList updated list to update play list.
     */
    public void update(ArrayList<Playable> updatedList){
        playList.clear();

        for (Playable p : updatedList){
            playList.add(p);
        }

        if (updatedList.isEmpty()){
            currentlyPlaying = null;
        }
        else if (currentlyPlaying == null){
            // currently playing is empty.
            // set first index of list.
            currentlyPlaying = playList.get(0);
        } else if (playList.indexOf(currentlyPlaying) == -1){
            // currently playing object is removed from list.
            // Go next object of same type.
            if (currentlyPlaying instanceof Video){
                // currently playing object is Video type
                next("Video");
            } else {
                // currently playing object is Audio type
                next("Audio");
            }
        }
    }

    /** Gives information about currently playing object. */
    public void info(){

        if (currentlyPlaying instanceof Audio) {
            Audio playable = (Audio) currentlyPlaying;

            System.out.println("Currently Viewing object Information");
            System.out.println("------------------------------------");
            System.out.println("Name: " + playable.getName());
            System.out.println("Duration: " + playable.getDuration());
            System.out.println("Other information: " + playable.getOtherInfo());
        } else {
            Video playable = (Video) currentlyPlaying;

            System.out.println("Currently Viewing object Information");
            System.out.println("------------------------------------");
            System.out.println("Name: " + playable.getName());
            System.out.println("Duration: " + playable.getDuration());
            System.out.println("Other information: " + playable.getOtherInfo());
        }
    }




    // Returns index of next object which is same type of parameter type.
    private int getNextTypeInPlayList(String type, int indexOfCurrent){
        int index = -1;

        if (type.equals("Video")){

            for (int i = indexOfCurrent+1; i < playList.size(); i++){
                if (playList.get(i) instanceof Video){
                    index = i;
                    break;
                }
            }

            // If index is still -1, there are two possibilities.
            // First one is that current object is the last object in
            // play list. So we should start from head of list to current object
            // and find first occurred Video object.
            // Second one is that there is no other Video object exists in the list.
            if (index == -1){
                for (int i = 0; i < indexOfCurrent; i++){
                    if (playList.get(i) instanceof Video){
                        index = i;
                        break;
                    }
                }
            }
        } else if (type.equals("Audio")){
            for (int i = indexOfCurrent+1; i < playList.size(); i++){
                if (playList.get(i) instanceof Audio){
                    index = i;
                    break;
                }
            }

            // If index is still -1, there are two possibilities.
            // First one is that current object is the last object in
            // view list. So we should start from head of list to current object
            // and find first occurred Audio object.
            // Second one is that there is no other Video object exists in the list.
            if (index == -1){
                for (int i = 0; i < indexOfCurrent; i++){
                    if (playList.get(i) instanceof Audio){
                        index = i;
                        break;
                    }
                }
            }
        }
        return index;
    }

    /** Plays/views next object in type of parameter type.
     *
     * @param type Type of object.
     */
    public void next(String type){
        int indexOfCurrent;
        if (currentlyPlaying instanceof Video){
            indexOfCurrent = playList.indexOf((Video) currentlyPlaying);
        } else {
            indexOfCurrent = playList.indexOf((Audio) currentlyPlaying);
        }


        if (type.equals("Video")){

            int indexOfNext = getNextTypeInPlayList("Video", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyPlaying = playList.get(indexOfNext);
            } else {
                // There is no Audio exist in viewList.
                currentlyPlaying = null;
            }
        } else if (type.equals("Audio")){
            int indexOfNext = getNextTypeInPlayList("Audio", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyPlaying = playList.get(indexOfNext);
            } else {
                // There is no Audio exist in viewList.
                currentlyPlaying = null;
            }
        }
    }



    private int getPreviousTypeInPlayList(String type, int indexOfCurrent){
        int index = -1;

        if (type.equals("Video")){
            for (int i = indexOfCurrent-1; i >= 0; i--){
                if (playList.get(i) instanceof Video){
                    index = i;
                    break;
                }
            }

            if (index == -1){
                for (int i = playList.size()-1; i > indexOfCurrent; i--){
                    if (playList.get(i) instanceof Video){
                        index = i;
                        break;
                    }
                }
            }

        } else if (type.equals("Audio")) {
            for (int i = indexOfCurrent-1; i >= 0; i--){
                if (playList.get(i) instanceof Audio){
                    index = i;
                    break;
                }
            }

            if (index == -1){
                for (int i = playList.size()-1; i > indexOfCurrent; i--){
                    if (playList.get(i) instanceof Audio){
                        index = i;
                        break;
                    }
                }
            }
        }

        return index;
    }



    /** Plays/views previous object in type of parameter type.
     *
     * @param type Type of object.
     */
    public void previous(String type){
        int indexOfCurrent;
        if (currentlyPlaying instanceof Video){
            indexOfCurrent = playList.indexOf((Video) currentlyPlaying);
        } else {
            indexOfCurrent = playList.indexOf((Audio) currentlyPlaying);
        }


        if (type.equals("Video")){

            int indexOfNext = getPreviousTypeInPlayList("Video", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyPlaying = playList.get(indexOfNext);
            } else {
                // There is no Audio exist in viewList.
                currentlyPlaying = null;
            }
        } else if (type.equals("Audio")){
            int indexOfNext = getPreviousTypeInPlayList("Audio", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyPlaying = playList.get(indexOfNext);
            } else {
                // There is no Audio exist in viewList.
                currentlyPlaying = null;
            }
        }
    }
}
