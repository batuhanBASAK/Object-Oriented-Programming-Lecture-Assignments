/** Audio class */
public class Audio extends Entry implements NonVisual, Playable{
    /** Duration time of Audio */
    private double duration;


    /** Constructor method.
     *
     * @param name Name of Audio.
     * @param duration Duration time of Audio.
     * @param otherInfo Other information of Audio.
     */
    public Audio(String name, double duration, String otherInfo){
        super(name, otherInfo);
        this.duration = duration;
    }

    /** Prints information of Playable object */
    public void informationOfPlayable(){
        System.out.println("Name: " + getName()
                + ", Type: Audio, Duration: " + duration
                + ", other information: " + getOtherInfo());
    }


    /** Getter method for duration
     *
     * @return duration time.
     */
    public double getDuration(){
        return duration;
    }

    /** Setter method for duration
     *
     * @param newDuration New duration time.
     */
    public void setDuration(double newDuration){
        this.duration = newDuration;
    }


    public void informationOfNonVisual(){
        System.out.println("Name: " + getName()
                + ", other information: " + getOtherInfo());
    }
}
