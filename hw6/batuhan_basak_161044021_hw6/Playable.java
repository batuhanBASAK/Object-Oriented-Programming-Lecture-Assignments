/** Playable interface */
public interface Playable {
    /** Getter method for duration.
     *
     * @return duration time.
     */
    public double getDuration();

    /** Setter method for duration.
     *
     * @param newDuration New duration time.
     */
    public void setDuration(double newDuration);

    /** Display information of each playable object */
    public void informationOfPlayable();
}
