package groceries;
import java.util.Date;
import java.util.ArrayList;

/**
 * @author melms
 *
 */
class Main {
    /**
     * @param args
     */
    public static void main(String[] args) {
        if (args.length >= 1) {
            String command = args[1];
            Database db = new Database();
            if (command == "showDonations") {
                db.showDonations();
            } else if (command == "showUsers") {
                db.showUsers();
            } else if (command == "postDelivery") {
                ArrayList<Donation> donations = new ArrayList<Donation>();
                donations.add(new Donation(3.0, 2, new Date(), new Date(), 2));
                donations.add(new Donation(4.0, 2, new Date(), new Date(), 2));
                donations.add(new Donation(3.0, 2, new Date(), new Date(), 2));
                Delivery d = new Delivery(donations);
                db.postDelivery(d);
            } else if (command == "register") {
                db.register(2, "helms107@mail.chapman.edu", "matthew", "helms", "8313349275", "abc123", "abc123");
            } else if (command == "resetTables") {
                db.createTables();
            } else if (command == "completeRegistration" && args.length >= 3) {
                db.completeRegistration(Integer.parseInt(args[2]), args[3]);
            }
            db.close();
        }
    }
}
