package com.company;

import org.omg.CORBA.TIMEOUT;

import java.time.Duration;
import java.util.Timer;

public class Complex {
    float realPart = 0;
    float imaginaryPart = 0;

    public Complex() {
        super();
    }

    public Complex(float a, float b) {
        this.realPart = a;
        this.imaginaryPart = b;
    }


    public boolean is_zero() {
        return ((this.realPart == 0) && (this.imaginaryPart == 0));
    }

    public float getRealPart() {
        return this.realPart;
    }

    public float getImaginaryPart() {
        return this.imaginaryPart;
    }

    public void setRealPart(float a) {
        this.realPart = a;
    }

    public void setImaginaryPart(float b) {
        this.imaginaryPart = b;
    }

    public Complex sum(Complex c) {
        return new Complex(this.realPart + c.getRealPart(), this.imaginaryPart + c.getImaginaryPart());
    }

    public Complex product(Complex c) {
        // not yet implemented
        Complex result = new Complex();
        result.realPart = this.realPart*c.getRealPart() + this.imaginaryPart*c.getImaginaryPart()*(-1);
        result.imaginaryPart = this.realPart*c.getImaginaryPart() + this.imaginaryPart*c.getRealPart();
        return result;
    }

    public Complex inverse() throws IllegalArgumentException {

        float square_norm = (this.realPart * this.realPart + this.imaginaryPart * this.imaginaryPart);

        if (is_zero()) throw new IllegalArgumentException();
        else return new Complex(this.realPart / square_norm, -this.imaginaryPart / square_norm);
    }

    @Override
    public String toString() {
        return realPart + "+i" + imaginaryPart;
    }

    public static void infinite()
    { // méthode à écrire
        int i=0;
        long start = System.currentTimeMillis();
        while (i < 1000){
            i++;
            System.out.println("#"+i);
        }
        long end = System.currentTimeMillis();
        long duree = end-start;
        System.out.println("time = "+duree);
    }
}