/** Text class */
public class Text extends Entry implements NonVisual, NonPlayable{
    /** Constructor method
     *
     * @param name Name of Text.
     * @param otherInfo Other information of text.
     */
    public Text(String name, String otherInfo){
        super(name, otherInfo);
    }

    /** Display information of each NonPlayable object */
    public void informationOfNonPlayable(){
        System.out.println("Name: " + getName()
                + ", other information: " + getOtherInfo());
    }

    /** Prints information of NonVisual object */
    public void informationOfNonVisual(){
        System.out.println("Name: " + getName()
                + ", other information: " + getOtherInfo());
    }

}
