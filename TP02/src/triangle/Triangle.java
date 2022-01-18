/**
 * nom : Triangle.java
 * auteurs : Yanis AMROUCHE & Farouk AGUENI
 * date de création : 12-01-2022
 */

package triangle;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Triangle {

    private float a, b, c;

    public Triangle(float coteA, float coteB, float coteC) {
        this.a = coteA;
        this.b = coteB;
        this.c = coteC;
    }

    public float getA() {
        return a;
    }

    public void setA(float a) {
        this.a = a;
    }

    public float getB() {
        return b;
    }

    public void setB(float b) {
        this.b = b;
    }

    public float getC() {
        return c;
    }

    public void setC(float c) {
        this.c = c;
    }

    public int typeTriangle(){
        if(a <= 0.0 || b <= 0.0 || c<= 0.0 || (a > b+c) || (b > a+c) || (c > a+b)){
            return -1;
        }else if (a==b && b==c)
        {
            return 3;
        }else if (a==b || a==c || b==c){
            return 2;
        }else{
            return 1;
        }
    }

    public static Triangle readData(String file) throws IOException {
        Triangle triangle;
        FileReader fr = new FileReader(file);
        Path path = Paths.get(file);
        if(Files.notExists(path) || Files.size(path) < 0){
            throw new FileNotFoundException();
        }
        BufferedReader reader = new BufferedReader(fr);
        LineNumberReader counter = new LineNumberReader(reader);

        List<String> numbers = new ArrayList<>();

        /*
        int nbByte = fr.read();
        if(nbByte == -1){
            triangle = new Triangle(0,0,0);
            return triangle;
        }
         */
        String line = null;
        while ((line = counter.readLine()) != null){
            System.out.println("---------->"+line);
            numbers.add(line);
        }

        System.out.println(numbers);
        triangle = new Triangle(Float.parseFloat(numbers.get(0)),Float.parseFloat(numbers.get(1)),Float.parseFloat(numbers.get(2)));
        return triangle;

    }


    public static void main(String[] args) throws IOException {
        Triangle triangle = readData("TP02/src/triangle/empty.txt");

    }



}
