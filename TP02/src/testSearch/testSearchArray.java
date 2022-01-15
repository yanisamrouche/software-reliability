package testSearch;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Random;

public class testSearchArray {
    int[] tab;

    @BeforeEach
    void setUp() throws Exception {
        int length = 10;
        tab = new int[length];
        Random random = new Random(50);
        for(int i=0; i<length; i++){
            int r = random.nextInt(50);
            tab[i] = r;
        }
        int tmp;
        // tri à bulle
        for(int i=0; i<length-1; i++){
            for(int j=0; j<length-i-1; j++){
                if(tab[j] > tab[j+1]){
                    tmp = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = tmp;
                }
            }
        }
    }

    @Test
    public void testSearchArrayClass1(){

    }






}
