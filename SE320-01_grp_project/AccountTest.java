package groceries;

import static org.junit.Assert.*;

import org.junit.Test;

public class AccountTest {

	@Test
	public void test1() {
		Account a = new Account(0, "driver", "Matthew", "helms", "helms107@mail.chapman.edu", "8313349275", "4abc142", "");
		String test = a.toString();
		String result = "id: 0\nrole: driver\nlicense: 4abc142\nname: Matthew helms\nemail: helms107@mail.chapman.edu\nphone: 8313349275\n";
		assertEquals(test, result);
	}
	
	@Test
	public void test2() {
		Account a = new Account(0, "driver", "Matthew", "helms", "helms107@mail.chapman.edu", "8313349275", "", "627819273");
		String test = a.toString();
		String result = "id: 0\nrole: driver\nemployer id: 627819273\nname: Matthew helms\nemail: helms107@mail.chapman.edu\nphone: 8313349275\n";
		assertEquals(test, result);
	}
	
	@Test
	public void test3() {
		Account a = new Account(0, "driver", "Matthew", "helms", "helms107@mail.chapman.edu", "8313349275", "", "");
		String test = a.toString();
		String result = "id: 0\nrole: driver\nname: Matthew helms\nemail: helms107@mail.chapman.edu\nphone: 8313349275\n";
		assertEquals(test, result);
	}

}
