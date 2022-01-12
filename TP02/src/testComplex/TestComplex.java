package testComplex;

import com.company.Complex;

/* nécessaire pour les timeout */
import static java.time.Duration.ofMillis;

/* importer les annotations utilisées*/
import com.sun.xml.internal.ws.policy.spi.AssertionCreationException;
import org.junit.jupiter.api.*;

import java.lang.reflect.Executable;
import java.time.Duration;
import java.util.function.Supplier;

public class TestComplex {

    Complex z0,z,z1,z2;
    @BeforeAll
    static void setUpBeforeClass() throws Exception {
        /*
         * ajouter un message
         */
        System.out.println("setUpBeforeClass ..."+System.currentTimeMillis());

    }

    @AfterAll
    static void tearDownAfterClass() throws Exception {
        /*
         * ajouter un message
         */
        System.out.println("tearDownAfterClass..."+System.currentTimeMillis());
    }

    @BeforeEach
    void setUp() throws Exception {
        /*
         * ajouter un message
         */
        System.out.println("setUp..."+System.currentTimeMillis());
        z = new Complex(1.0F, 2.0f);
        z0 = new Complex(0.0F, 0.0f);
        z1 = new Complex(1.0F, 2.0F);
        z2 = new Complex(3.0F, 4.0F);
    }

    @AfterEach
    void tearDown() throws Exception {
        /*
         * ajouter un message
         */
        System.out.println("tearDown..."+System.currentTimeMillis());
    }

    /** test réussis car expected == z.getImaginaryPart() */
    @Test
    public void testGetterImaginary() {

        float expected = 2.0F;

        Assertions.assertTrue(expected == z.getImaginaryPart(), "problem on getter imaginary");

    }

    @Test
    public void testGetterReal() {

        float expected = 1.0F;

        Assertions.assertTrue(expected == z.getRealPart(), "problem on getter real");

    }

    @Test
    public void testSetterImaginary() {

        float expected = 3.0F;
        z.setImaginaryPart(3.F);

        Assertions.assertTrue(expected == z.getImaginaryPart(), "problem on setter Imaginary");

    }

    @Test
    public void testSetterReal() {

        float expected = 3.0F;
        z.setRealPart(3.0F);

        Assertions.assertTrue(expected == z.getRealPart(), "problem on setter Real");
    }

    @Test
    public void testZeroTrue() {
        z.setRealPart(0.0F);
        z.setImaginaryPart(0.0F);

        Assertions.assertTrue(z.is_zero(), "problem with is_zero on Zero Complex number");

    }

    @Test
    public void testZeroFalse() {
        z.setRealPart(1.0F);
        z.setImaginaryPart(1.0F);

        Assertions.assertFalse(z.is_zero(), "problem with is_zero on non Zero Complex number");

    }

    @Test
    public void testSumReal() {
        float expected = 1.0F + 3.0F;

        Complex z = z1.sum(z2);

        Assertions.assertTrue(z.getRealPart() == expected, "problem with Real part of Sum");
    }

    @Test
    public void testSumImaginary() {
        float expected = 2.0F + 4.0F;
        Complex z = z1.sum(z2);

        Assertions.assertTrue(z.getImaginaryPart() == expected, "problem with Imaginary part of Sum");
    }

    @Test
    public void testInverseReal(){
        float expected = 0.2F;
        Complex z_inverse = z.inverse();
        System.out.println(z_inverse.getRealPart());
        Assertions.assertTrue(z_inverse.getRealPart() == expected, "problem with Real part of Sum");

    }

    @Test
    public void testInverseImaginary(){
        float expected = -0.4F;
        Complex z_inverse = z.inverse();
        System.out.println(z_inverse.getImaginaryPart());
        Assertions.assertTrue(z_inverse.getImaginaryPart() == expected, "problem with imaginary part of Sum");

    }

    @Test
    public void testInverseZero(){

        try {
            z0.inverse();
        }catch (IllegalArgumentException e){
            e.getMessage();
        }




    }


    @Test
    public void testProductReal() {

        float expected = 1.0F * 3.0F - 2.0F * 4.0F;

        Complex z = z1.product(z2);

        Assertions.assertTrue(z.getRealPart() == expected, "problem with Real part of Product");

    }


    @Test
    public void testProductImaginary() {
        //Complex z1 = new Complex(1.0F, 2.0F);
        //Complex z2 = new Complex(3.0F, 4.0F);

        float expected = 1.0F * 4.0F + 2.0F * 3.0F;

        Complex z = z1.product(z2);

        Assertions.assertTrue(z.getImaginaryPart() == expected, "problem with Real part of Product");

    }





    /*
     * Ecrire un test qui échoue si le calcul avec infinite prend trop de temps
     */
    @Test
    public final void testTimeoutInfinite(){
        Assertions.assertTimeoutPreemptively(Duration.ofMillis(100),()->{Complex.infinite();});
    }


}