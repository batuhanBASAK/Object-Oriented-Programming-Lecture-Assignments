/** Entry class */
public class Entry {
    /** Name of Entry */
    private String name;

    /** Other information of Entry */
    private String otherInfo;

    /** Constructor method
     *
     * @param name Name of Entry.
     * @param otherInfo Other information of Entry.
     */
    public Entry(String name, String otherInfo){
        this.name = name;
        this.otherInfo = otherInfo;
    }

    /** Getter method for name
     *
     * @return The name of Entry.
     */
    public String getName() {
        return name;
    }



    /** Getter method for other information of Entry.
     *
     * @return The other information of Entry.
     */
    public String getOtherInfo() {
        return otherInfo;
    }

    /** Setter method for name of Entry.
     *
     * @param newName New name of Entry.
     */
    public void setName(String newName){
        this.name = newName;
    }

    /** Setter method for other information of Entry.
     *
     * @param newOtherInfo New other information of Entry.
     */
    public void setOtherInfo(String newOtherInfo){
        this.otherInfo = newOtherInfo;
    }

}
