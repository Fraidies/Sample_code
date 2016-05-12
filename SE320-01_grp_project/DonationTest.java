package groceries;

import static org.junit.Assert.*;

import java.text.SimpleDateFormat;
import java.util.Date;

import org.junit.Test;

public class DonationTest {

	@Test
	public void test1() {
		Donation a = new Donation(15.0, 1, "2/12/16", "2/20/16", 0);
		String test = a.toString();
		String result = "weight: 15.0\ntype: 1\nlog date: 2/12/16\nexpiration date: 2/20/16\ngiver id: 0\n";
		assertEquals(test, result);
	}
	
	@Test
	public void test2() {
	    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
	    String d = sdf.format(new Date());
		Donation a = new Donation(15.0, 1, new Date(), new Date(), 0);
		String test = a.toString();
		String result = "weight: 15.0\ntype: 1\nlog date: "+d+"\nexpiration date: "+d+"\ngiver id: 0\n";
		assertEquals(test, result);
	}

}
