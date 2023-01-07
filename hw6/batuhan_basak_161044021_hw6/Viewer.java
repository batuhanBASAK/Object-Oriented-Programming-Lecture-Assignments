import java.util.ArrayList;
import java.util.List;

/** Viewer class */
public class Viewer implements Observer{

    /** This is the Visual object that is currently viewed by Viewer */
    private Visual currentlyViewing;

    /** View list. */
    private List<Visual> viewList = new ArrayList<Visual>();


    public Viewer(){
        currentlyViewing = null;
    }


    /** Getter method for currentlyViewing object
     *
     * @return currently viewing object.
     */
    public Visual getCurrentlyViewing(){
        return currentlyViewing;
    }

    /** Shows all view list */
    public void showList(){
        for (Visual v : viewList){
            v.informationOfVisual();
        }
    }


    /** Update view list respect to updated list
     *
     * @param updatedList Updated list to update view list.
     */
    public void update(ArrayList<Visual> updatedList){
        viewList.clear();

        for (Visual p : updatedList){
            viewList.add(p);
        }

        if (updatedList.isEmpty()){
            currentlyViewing = null;
        }
        else if (currentlyViewing == null){
            // currently viewing is empty.
            // set first index of list.
            currentlyViewing = viewList.get(0);
        } else if (viewList.indexOf(currentlyViewing) == -1){
            // currently viewing object is removed from list.
            // Go next object of same type.
            if (currentlyViewing instanceof Video){
                // currently viewing object is Video type
                next("Video");
            } else {
                // currently viewing object is Image type
                next("Image");
            }
        }
    }

    /** Gives information about currently viewing object. */
    public void info(){

        if (currentlyViewing instanceof Image) {
            Image visual = (Image) currentlyViewing;

            System.out.println("Currently Viewing object Information");
            System.out.println("------------------------------------");
            System.out.println("Name: " + visual.getName());
            System.out.println("Dimension information: " + visual.getDimensionInfo());
            System.out.println("Other information: " + visual.getOtherInfo());
        } else {
            Video visual = (Video) currentlyViewing;

            System.out.println("Currently Viewing object Information");
            System.out.println("------------------------------------");
            System.out.println("Name: " + visual.getName());
            System.out.println("Dimension information: " + visual.getDimensionInfo());
            System.out.println("Other information: " + visual.getOtherInfo());

        }
    }

    // Returns index of next object which is same type of parameter type.
    private int getNextTypeInPlayList(String type, int indexOfCurrent){
        int index = -1;

        if (type.equals("Video")){
            for (int i = indexOfCurrent+1; i < viewList.size(); i++){
                if (viewList.get(i) instanceof Video){
                    index = i;
                    break;
                }
            }

            // If index is still -1, there are two possibilities.
            // First one is that current object is the last object in
            // view list. So we should start from head of list to current object
            // and find first occurred Video object.
            // Second one is that there is no other Video object exists in the list.
            if (index == -1){
                for (int i = 0; i < indexOfCurrent; i++){
                    if (viewList.get(i) instanceof Video){
                        index = i;
                        break;
                    }
                }
            }
        } else if (type.equals("Image")){
            for (int i = indexOfCurrent+1; i < viewList.size(); i++){
                if (viewList.get(i) instanceof Image){
                    index = i;
                    break;
                }
            }

            // If index is still -1, there are two possibilities.
            // First one is that current object is the last object in
            // view list. So we should start from head of list to current object
            // and find first occurred Video object.
            // Second one is that there is no other Video object exists in the list.
            if (index == -1){
                for (int i = 0; i < indexOfCurrent; i++){
                    if (viewList.get(i) instanceof Image){
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
        if (currentlyViewing instanceof Video){
            indexOfCurrent = viewList.indexOf((Video) currentlyViewing);
        } else {
            indexOfCurrent = viewList.indexOf((Image) currentlyViewing);
        }

        if (type.equals("Video")){
            int indexOfNext = getNextTypeInPlayList("Video", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyViewing = viewList.get(indexOfNext);
            } else {
                // There is no Image exist in viewList.
                currentlyViewing = null;
            }
        } else if (type.equals("Image")){
            int indexOfNext = getNextTypeInPlayList("Image", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyViewing = viewList.get(indexOfNext);
            } else {
                // There is no Image exist in viewList.
                currentlyViewing = null;
            }
        }
    }


    private int getPreviousTypeInPlayList(String type, int indexOfCurrent){
        int index = -1;

        if (type.equals("Video")){
            for (int i = indexOfCurrent-1; i >= 0; i--){
                if (viewList.get(i) instanceof Video){
                    index = i;
                    break;
                }
            }

            if (index == -1){
                for (int i = viewList.size()-1; i > indexOfCurrent; i--){
                    if (viewList.get(i) instanceof Video){
                        index = i;
                        break;
                    }
                }
            }

        } else if (type.equals("Video")) {
            for (int i = indexOfCurrent-1; i >= 0; i--){
                if (viewList.get(i) instanceof Video){
                    index = i;
                    break;
                }
            }

            if (index == -1){
                for (int i = viewList.size()-1; i > indexOfCurrent; i--){
                    if (viewList.get(i) instanceof Image){
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
        if (currentlyViewing instanceof Video){
            indexOfCurrent = viewList.indexOf((Video) currentlyViewing);
        } else {
            indexOfCurrent = viewList.indexOf((Image) currentlyViewing);
        }


        if (type.equals("Video")){

            int indexOfNext = getPreviousTypeInPlayList("Video", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyViewing = viewList.get(indexOfNext);
            } else {
                // There is no Audio exist in viewList.
                currentlyViewing = null;
            }
        } else if (type.equals("Image")){
            int indexOfNext = getPreviousTypeInPlayList("Image", indexOfCurrent);

            if (indexOfNext != -1){
                currentlyViewing = viewList.get(indexOfNext);
            } else {
                // There is no Audio exist in viewList.
                currentlyViewing = null;
            }
        }
    }
}
