import javax.swing.text.View;
import java.io.ObjectStreamException;
import java.util.ArrayList;
import java.util.List;

/** Dataset class */
public class Dataset {
    /** Array of entries */
    private List<Entry> entries = new ArrayList<Entry>();

    /** Array of Observers */
    private List<Observer> observers = new ArrayList<Observer>();

    /** Add a new Entry to Dataset
     *
     * @param newEntry New Entry.
     */
    public void add(Entry newEntry){
        entries.add(newEntry);

        // Inform observers about changing.
        if (newEntry instanceof Playable){
            infoObserversAboutUpdate("Playable");
        }
        if (newEntry instanceof Visual){
            infoObserversAboutUpdate("Visual");
        }
    }

    /** Remove an existing Entry from dataset.
     *
     * @param entry Entry object to remove.
     */
    public void remove(Entry entry){
        entries.remove(entry);

        // Inform observers about changing.
        if (entry instanceof Playable){
            infoObserversAboutUpdate("Playable");
        }
        if (entry instanceof Visual){
            infoObserversAboutUpdate("Visual");
        }
    }

    /** Remove an existing Playable object from dataset.
     *
     * @param p Playable Entry object to remove.
     */
    public void remove(Playable p){
        entries.remove(p);
        // Inform observers about changing.
        if (p instanceof Playable){
            infoObserversAboutUpdate("Playable");
        }
        if (p instanceof Visual){
            infoObserversAboutUpdate("Visual");
        }
    }

    /** Remove an existing Visual object from dataset.
     *
     * @param v Visual Entry object to remove.
     */
    public void remove(Visual v){
        entries.remove(v);
        // Inform observers about changing.
        if (v instanceof Playable){
            infoObserversAboutUpdate("Playable");
        }
        if (v instanceof Visual){
            infoObserversAboutUpdate("Visual");
        }
    }



    /** Register new observer to the Dataset
     *
     * @param newObserver New observer to register.
     */
    public void register(Observer newObserver){
        observers.add(newObserver);
    }

    /** Unregister an existing obserser from dataset
     *
     * @param observer Observer object to unregister.
     */
    public void unregister(Observer observer){
        int index = observers.indexOf(observer);

        // Remove list from observer
        if (observers.get(index) instanceof Player){
            ((Player) observers.get(index)).update(new ArrayList<Playable>());
        } else {
            ((Viewer) observers.get(index)).update(new ArrayList<Visual>());
        }
        observers.remove(observer); // remove observer.
    }


    /** Inform observers of given type for update and send updated list of
     * that type of Entry.
     * @param type Type of Entry has been updated.
     */
    public void infoObserversAboutUpdate(String type){
        if (type.equals("Playable")){
            // Array of Playable to send observers an updated play list.
            ArrayList<Playable> playList = new ArrayList<Playable>();

            // Append each Playable object to play list.
            for (Entry e : entries){
                if (e instanceof Playable){
                    playList.add((Playable) e);
                }
            }

            // Update each Player object in observers with updated play list.
            for (Observer o : observers){
                if (o instanceof Player){
                    ((Player) o).update(playList);
                }
            }
        } else if (type.equals("Visual")){
            // Array of Playable to send observers an updated play list.
            ArrayList<Visual> playList = new ArrayList<Visual>();

            // Append each Playable object to play list.
            for (Entry e : entries){
                if (e instanceof Visual){
                    playList.add((Visual) e);
                }
            }

            // Update each Player object in observers with updated play list.
            for (Observer o : observers){
                if (o instanceof Viewer){
                    ((Viewer) o).update(playList);
                }
            }
        }
    }

}
