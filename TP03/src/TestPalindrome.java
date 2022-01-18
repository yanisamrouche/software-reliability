import org.junit.jupiter.api.*;

public class TestPalindrome {

    @Test
    public void testEmptyString(){

        Assertions.assertTrue(Palindrome.isPalindrome(""));

}

    @Test
    public void testEvenLengthFalse() {

        Assertions.assertFalse(Palindrome.isPalindrome("abcd"));
   }

    @Test
    public void testEvenLengthTrue() {

        Assertions.assertTrue(Palindrome.isPalindrome("abba"));
    }

    @Test
    public void testOddLengthTrue() {

        Assertions.assertTrue(Palindrome.isPalindrome("aba"));
    }


}
