/*initial class test for stringArray */

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


import java.util.Arrays;

class TestStringArray {

	    private static String[] slist1={
			"a","b","ccc","ccd","d","e","f","g"
		};
		private static String[] slist2={
			"ab","ccd","ccc","g","f","e","d"
		};

		private static String[] slist3={
				"ab", "ab"
		};

		private static String[] slist4={
				"ab", "c", "ab"
		};


		private StringArray array1;
		private StringArray array2;

	@BeforeAll
	static void setUpBeforeClass() throws Exception {
		 System.out.println("debut des tests");
	}

	@AfterAll
	static void tearDownAfterClass() throws Exception {
		 System.out.println("fin des tests");
	}

	@BeforeEach
	void setUp() throws Exception {
		 System.out.println("debut du test");
	}

	@AfterEach
	void tearDown() throws Exception {
		 System.out.println("fin du test");
	}
	
	@Test
	public void testSize() {
		array1=new StringArray(slist1);
		array2=new StringArray(slist2);		
		assertEquals(7,array2.size());
		assertEquals(8,array1.size());
	}
	
	@Test
	public void test1IndexOf() {
		array2=new StringArray(slist2);
		assertEquals(-1,array2.IndexOf("ee"));
	}
	
	@Test
	public void test2IndexOf() {
		array2=new StringArray(slist2);
		assertEquals(3,array2.IndexOf("d"));
	}

	@Test
	public void test3IndexOf(){
		array1 =new StringArray(slist1);
		assertEquals(-1, array1.IndexOf("zz"));
	}

	@Test
	public void test4IndexOf(){
		array1 =new StringArray(slist1);
		assertEquals(1, array1.IndexOf("b"));
	}

	@Test
	public void testConstructeur(){
		String[] strings = {"ab"};
		array1 = new StringArray(slist3);
		assertTrue(Arrays.equals(strings,array1.getMlist()));
	}

	@Test
	public void testConstructeur2(){
		String[] strings = {"ab", "c"};
		array1 = new StringArray(slist4);
		assertTrue(Arrays.equals(strings,array1.getMlist()));
	}

	@Test
	public void testGetString(){
		array1 = new StringArray(slist1);
		assertEquals("b", array1.getString(1));
	}

	@Test
	public void testSizeOf(){
		array1 = new StringArray(slist1);
		assertEquals(8, array1.size());
	}
	
}
