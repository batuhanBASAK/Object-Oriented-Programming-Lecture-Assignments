/** Image class */
public class Image extends Entry implements Visual, NonPlayable{

    /** Dimension information of Image */
    private String dimensionInfo;


    /** Constructor method
     *
     * @param name Name of Image.
     * @param dimensionInfo Dimesion information of Image.
     * @param otherInfo Other information of Image.
     */
    public Image(String name, String dimensionInfo, String otherInfo){
        super(name, otherInfo);
        this.dimensionInfo = dimensionInfo;
    }

    /** Getter method for DimensionInfo
     *
     * @return Dimension information.
     */
    public String getDimensionInfo(){
        return dimensionInfo;
    }

    /** Setter method for DimensionInfo
     *
     * @param newDimensionInfo New dimension information of Object.
     */
    public void setDimensionInfo(String newDimensionInfo){
        this.dimensionInfo = dimensionInfo;
    }

    /** Prints information of Visual object */
    public void informationOfVisual(){
        System.out.println("Name: " + getName()
                + ", Type: Image, Dimension: " + getDimensionInfo()
                + ", other information: " + getOtherInfo());
    }

    /** Display information of each NonPlayable object */
    public void informationOfNonPlayable(){
        System.out.println("Name: " + getName()
                + ", other information: " + getOtherInfo());
    }
}
