package testTriangle;
import org.junit.jupiter.api.*;
import triangle.Triangle;

import java.io.FileNotFoundException;
import java.io.IOException;

public class TestTriangle {
    private Triangle triangle;
    @BeforeEach
    void setUp() throws Exception {
        triangle = new Triangle(2,1,2);
    }


    @Test
    public void testTypeTriangleIsoceleAC(){
        Assertions.assertTrue(triangle.typeTriangle() == 2);
    }
    @Test
    public void testTypeTriangleIsoceleAB(){
        triangle.setB(2);
        triangle.setC(1);
        Assertions.assertTrue(triangle.typeTriangle() == 2);
    }
    @Test
    public void testTypeTriangleIsoceleBC(){
        triangle.setB(2);
        triangle.setC(2);
        triangle.setA(1);
        Assertions.assertTrue(triangle.typeTriangle() == 2);
    }
    @Test
    public void testTypeTriangleEquilateral(){
        triangle.setB(2);
        Assertions.assertTrue(triangle.typeTriangle() == 3);
    }

    @Test
    public void testTypeTriangleAnull(){
        triangle.setA(0);
        Assertions.assertTrue(triangle.typeTriangle() == -1);
    }
    @Test
    public void testTypeTriangleAneg(){
        triangle.setA(-1);
        Assertions.assertTrue(triangle.typeTriangle() == -1);
    }
    @Test
    public void testTypeTriangleBnull(){
        triangle.setA(0);
        Assertions.assertTrue(triangle.typeTriangle() == -1);
    }
    @Test
    public void testTypeTriangleBneg(){
        triangle.setA(-1);
        Assertions.assertTrue(triangle.typeTriangle() == -1);
    }
    @Test
    public void testTypeTriangleCnull(){
        triangle.setA(0);
        Assertions.assertTrue(triangle.typeTriangle() == -1);
    }
    @Test
    public void testTypeTriangleCneg(){
        triangle.setA(-1);
        Assertions.assertTrue(triangle.typeTriangle() == -1);
    }

    @Test
    public void testTypeTriangleScalene(){
        triangle.setA(1);
        triangle.setB(1.1F);
        triangle.setC(0.5F);
        Assertions.assertTrue(triangle.typeTriangle() == 1);
    }

    @Test
    public void testReadData() throws IOException {
        Triangle triangle = Triangle.readData("TP02/src/triangle/triangle.txt");
        Assertions.assertTrue((triangle.getA() == 5) && (triangle.getB() == 3) && (triangle.getC() == 3));
    }

    @Test
    public void testReadDataFileDoNotExists() throws IOException {
        try {
            Triangle triangle = Triangle.readData("TP02/src/triangle/triangle1.txt");
            Assertions.assertTrue((triangle.getA() == 0) && (triangle.getB() == 0) && (triangle.getC() == 0));
        }catch (FileNotFoundException fileNotFoundException){
            fileNotFoundException.getMessage();
        }

    }

    @Test
    public void testReadDataEmptyFile() throws IOException {
        try {
            Triangle triangle = Triangle.readData("TP02/src/triangle/empty.txt");
            Assertions.assertTrue((triangle.getA() == 0) && (triangle.getB() == 0) && (triangle.getC() == 0));
        }catch (Exception e){
            e.getMessage();
        }
    }


}
