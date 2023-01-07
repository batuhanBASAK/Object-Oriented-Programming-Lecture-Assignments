/** Video class */
public class Video extends Entry implements Playable, Visual{

    /** Duration time of Video */
    private double duration;

    /** Dimension information of Video */
    private String dimensionInfo;


    /** Constructor method
     *
     * @param name Name of Video.
     * @param duration Duration time of Video.
     * @param dimensionInfo Dimension information of Video.
     * @param otherInfo Other information of Video.
     */
    public Video(String name, double duration, String dimensionInfo, String otherInfo){
        super(name, otherInfo);
        this.duration = duration;
        this.dimensionInfo = dimensionInfo;
    }


    /** Prints information of Playable object */
    public void informationOfPlayable(){
        System.out.println("Name: " + getName()
            + ", Type: Video, Duration: " + duration
            + ", other information: " + getOtherInfo());
    }

    /** Prints information of Visual object */
    public void informationOfVisual(){
        System.out.println("Name: " + getName()
                + ", Type: Video, Dimension: " + getDimensionInfo()
                + ", other information: " + getOtherInfo());
    }

    /** Getter method for duration
     *
     * @return duration time.
     */
    public double getDuration(){
        return duration;
    }

    /** Setter method for duration.
     *
     * @param newDuration New duration time.
     */
    public void setDuration(double newDuration){
        this.duration = newDuration;
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
        this.dimensionInfo = newDimensionInfo;
    }

}
