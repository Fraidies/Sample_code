package groceries;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Date;

import org.junit.Test;

public class DatabaseTest {

	@Test
	public void test1() {
		Database d = new Database();
		d.createTables();
		assertEquals(d.register(0, "'****************", "*******", "*****", "***********", "****", "****"), false);
		d.close();
	}
	
	@Test
	public void test2() {
		Database d = new Database();
		d.createTables();
		assertEquals(d.register(0, "'****************", "*******", "*****", "***********", "****", "****"), true);
		d.close();
	}
	
	@Test
	public void test3() {
		Database d = new Database();
		d.createTables();
		d.register(0, "'****************", "*******", "*****", "***********", "****", "****");
		assertEquals(d.register(0, "'****************", "*******", "*****", "***********", "****", "****"), false);
		d.close();
	}
	
	@Test
	public void test4() {
		Database d = new Database();
		d.createTables();
		assertEquals(d.register(0, "'****************", "*******", "*****", "***********", "****", "****"), false);
		d.close();
	}
	
	@Test
	public void test5() {
		Database d = new Database();
		d.createTables();
		assertEquals(d.register(0,"'****************", "*******", "*****", "***********", "****", "****"), false);
		d.close();
	}
	
	@Test
	public void test6() {
		Database d = new Database();
		d.createTables();
		d.register(1, "'****************", "*******", "*****", "***********", "****", "****");
		d.showUsers();
		assertEquals(d.completeRegistration(1, "*****"), true);
		d.close();
	}
	
	@Test
	public void test7() {
		Database d = new Database();
		d.createTables();
		d.register(1, "'****************", "*******", "*****", "***********", "****", "****");
		d.showUsers();
		assertEquals(d.completeRegistration(1, "****'--"), false);
		d.close();
	}
	
	@Test
	public void test8() {
		Database d = new Database();
		d.createTables();
		ArrayList<Donation> donations = new ArrayList<Donation>();
        donations.add(new Donation(4.0, 2, new Date(), new Date(), 2));
        donations.add(new Donation(4.0, 2, new Date(), new Date(), 2));
        donations.add(new Donation(3.0, 2, new Date(), new Date(), 2));
        Delivery del = new Delivery(donations);
		d.postDelivery(del);
		assertEquals(d.showDonations(), true);
		d.close();
	}
	
	@Test
	public void test9() {
		Database d = new Database();
		d.createTables();
		ArrayList<Donation> donations = new ArrayList<Donation>();
        donations.add(new Donation(4.0, 2, new Date(), new Date(), 2));
        donations.add(new Donation(4.0, 2, new Date(), new Date(), 2));
        donations.add(new Donation(1.0, 2, new Date(), new Date(), 2));
        Delivery del = new Delivery(donations);
		assertEquals(d.postDelivery(del), false);
		d.close();
	}
	
	@Test
	public void test10() {
		Database d = new Database();
		d.createTables();
		d.register(1, "'****************", "*******", "*****", "***********", "****", "****");
		assertEquals(d.login("*****************", "*****"), "*");
		d.close();
	}
	
	@Test
	public void test11() {
		Database d = new Database();
		d.createTables();
		assertEquals(d.login("*********************", "*********"), "-1");
		d.close();
	}
	
	@Test
	public void test12() {
		Database d = new Database();
		d.createTables();
		assertEquals(d.login("***********************", "*************'---"), "-1");
		d.close();
	}

}
