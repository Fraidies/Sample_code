package groceries;
import java.util.ArrayList;

//DELIVERY CLASS HOLDS A LIST OF THE DONATIONS AND A TOTAL DONATION WEIGHT
/**
 * @author melms
 *
 */
class Delivery {
 public ArrayList<Donation> donations = new ArrayList<Donation>();
 public double totalWeight = 0.0;

 /**
 * @param _donations
 */
Delivery(ArrayList<Donation> _donations) {
     donations = _donations;

     // LOOPS THROUGH DONATIONS TO CALCULATE TOTAL WEIGHT
     for (int i = 0; i < donations.size(); i++) {
         totalWeight += donations.get(i).weight;
     }
 }
}
