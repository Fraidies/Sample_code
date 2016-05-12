package groceries;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Date;

import org.junit.Test;

public class DeliveryTest {

	@Test
	public void test1() {
		ArrayList<Donation> donations = new ArrayList<Donation>();
        donations.add(new Donation(3.0, 2, new Date(), new Date(), 2));
        donations.add(new Donation(4.0, 2, new Date(), new Date(), 2));
        donations.add(new Donation(3.0, 2, new Date(), new Date(), 2));
        Delivery d = new Delivery(donations);
		Double test = d.totalWeight;
		Double result = 10.0;
		assertEquals(test, result);
	}

}
