package groceries;


/**Class that manages users in relation to a database
 * @author Matthew Helms
 * @version 1.0
 */

class Account {
    public int id = 0;
    public String role = ""; //user role - Driver, Giver, Getter
    public String first = ""; // Name
    public String last = "";
    public String email = ""; // Reachable email account
    public String phone = ""; // (SmartPhone) phone number
    public String driversLicense = ""; //US State ID
    public String employerID = "";

    /**
     * Construct Account
     * @param id
     * @param role
     * @param first
     * @param last
     * @param email
     * @param phone
     * @param driversLicense
     * @param employerID
     * @return Account
     */
    Account(int _id, String _role, String _first, String _last, String _email, String _phone, String _driversLicense, String _employerID) {
        id = _id;
        role = _role;
        first = _first;
        last = _last;
        email = _email;
        phone = _phone;
        driversLicense = _driversLicense;
        employerID = _employerID;
    }

    /**
     * ToString Method
     * @return String
     */
    public String toString() {
        if (!driversLicense.equals("")) {
            return String.format("id: %d\nrole: %s\nlicense: %s\nname: %s %s\nemail: %s\nphone: %s\n", id, role, driversLicense, first, last, email, phone);
        } else if (!employerID.equals("")) {
            return String.format("id: %d\nrole: %s\nemployer id: %s\nname: %s %s\nemail: %s\nphone: %s\n", id, role, employerID, first, last, email, phone);
        }
        return String.format("id: %d\nrole: %s\nname: %s %s\nemail: %s\nphone: %s\n", id, role, first, last, email, phone);
    } // converts the users account information into a string to be displayed
      // if = Driver, else if = Giver, else = Getter
}
