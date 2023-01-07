/** Observer interface */
public interface Observer {

    /** Display each object that observed by this object */
    public void showList();


    /** Display information of currently playing/viewing object */
    public void info();

    /** Plays/views next object in type of parameter type.
     *
     * @param type Type of object.
     */
    public void next(String type);


    /** Plays/views previous object in type of parameter type.
     *
     * @param type Type of object.
     */
    public void previous(String type);

}
