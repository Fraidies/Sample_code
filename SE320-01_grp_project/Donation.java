package groceries;
import java.util.Date;
import java.text.SimpleDateFormat;

// DONATION CLASS HOLDS A DONATION CATAGORY
/**
 * @author melms
 *
 */
class Donation {
    private SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    public double weight = 0;
    public int type = 0;
    public String logDate = "";
    public String expDate = "";
    public int giverID = 0;

    // CONSTRUCTOR REQUIRING DATES AS STRINGS
    /**
     * @param _weight
     * @param _type
     * @param _logDate
     * @param _expDate
     * @param _giverID
     */
    Donation(double _weight, int _type, String _logDate, String _expDate, int _giverID) {
        weight = _weight;
        type = _type;
        logDate = _logDate;
        expDate = _expDate;
        giverID = _giverID;
    }

    // CONSTRUCTOR REQUIRING DATES AS DATES
    /**
     * @param _weight
     * @param _type
     * @param _logDate
     * @param _expDate
     * @param _giverID
     */
    Donation(double _weight, int _type, Date _logDate, Date _expDate, int _giverID) {
        weight = _weight;
        type = _type;
        logDate = sdf.format(_logDate);
        expDate = sdf.format(_expDate);
        giverID = _giverID;
    }

    // TO STRING FOR CONSOLE OUTPUT
    /* (non-Javadoc)
     * @see java.lang.Object#toString()
     */
    public String toString() {
        return String.format("weight: %s\ntype: %d\nlog date: %s\nexpiration date: %s\ngiver id: %d\n", weight, type, logDate, expDate, giverID);
    }
}
