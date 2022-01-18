/**
 * nom : testSearchArray.java
 * auteurs : Yanis AMROUCHE & Farouk AGUENI
 * date de création : 12-01-2022
 */
/**
package testArraySearch;
import com.company.search_Array_Class_1;
import com.company.search_Array_Class_2;
import com.company.search_Array_Class_3;
import com.company.search_Array_Class_4;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

import java.time.Duration;
import java.util.Random;

public class testSearchArray {
    private int[] tab = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    private int[] tab2 = new int[]{0, 1, 2, 3, 3, 5, 6};

    private  int[] empty = new int[1];;
    private search_Array_Class_1 search_array_class_1 = new search_Array_Class_1();
    private search_Array_Class_2 search_array_class_2 = new search_Array_Class_2();
    private search_Array_Class_3 search_array_class_3 = new search_Array_Class_3();
    private search_Array_Class_4 search_array_class_4 = new search_Array_Class_4();


    //=========================== Test sur la Class1 ================================//
   @Test
   public void testSearchArrayClass1EmptyTab(){
       int index = search_array_class_1.search(empty, 3);
       System.out.println(index);
       Assertions.assertTrue(index == -1);
   }

   @Test
   public void testSearchArrayClass1ElementDoesNotExist(){
       int index = search_array_class_1.search(tab, 12);
       Assertions.assertTrue(index == -1);
   }

   @Test
   public void testSearchArrayClass1MinIndex(){
       int index = search_array_class_1.search(tab2, 3);
       Assertions.assertTrue(index == 3);
   }

    @Test
    public void testSearchArrayClass1(){

       int index = search_array_class_1.search(tab, 4);
        Assertions.assertTrue(index == 4);

    }
    //=========================== Test sur la Class2 ================================//
    @Test
    public void testSearchArrayClass2EmptyTab(){
        int index = search_array_class_2.search(empty, 3);
        Assertions.assertTrue(index == -1);
    }

    @Test
    public void testSearchArrayClass2ElementDoesNotExist(){
        int index = search_array_class_2.search(tab2, 4);
        Assertions.assertTrue(index == -1);
    }

    @Test
    public void testSearchArrayClass2MinIndex(){
        int index = search_array_class_2.search(tab2, 3);
        Assertions.assertTrue(index == 3);
    }

    @Test
    public void testSearchArrayClass2(){
        int index = search_array_class_2.search(tab, 8);
        Assertions.assertTrue(index == 8);
    }
    //=========================== Test sur la Class3 ================================//
    @Test
    public void testSearchArrayClass3EmptyTab(){
        int index = search_array_class_3.search(empty, 3);
        Assertions.assertTrue(index == -1);
    }

    @Test
    public void testSearchArrayClass3ElementDoesNotExist(){
        Assertions.assertTimeoutPreemptively(Duration.ofMillis(100),()->{search_array_class_3.search(tab, 12);});
        int index = search_array_class_3.search(tab, 12);
        Assertions.assertTrue(index == -1);

    }

    @Test
    public void testSearchArrayClass3MinIndex(){
        Assertions.assertTimeoutPreemptively(Duration.ofMillis(100),()->{
            int index = search_array_class_3.search(tab2, 3);
            Assertions.assertTrue(index == 3);

        });


    }
    @Test
    public void testSearchArrayClass3(){
        Assertions.assertTimeoutPreemptively(Duration.ofMillis(100),()->{search_array_class_3.search(tab, 11);});
    }
    //=========================== Test sur la Class4 ================================//
    @Test
    public void testSearchArrayClass4EmptyTab(){
        int index = search_array_class_4.search(empty, 3);
        Assertions.assertTrue(index == -1);
    }
    @Test
    public void testSearchArrayClass4ElementDoesNotExist(){
        int index = search_array_class_4.search(tab, 12);
        Assertions.assertTrue(index == -1);
    }
    @Test
    public void testSearchArrayClass4MinIndex(){
        int index = search_array_class_4.search(tab2, 3);
        Assertions.assertTrue(index == 3);
    }
    @Test
    public void testSearchArrayClass4(){
        int index = search_array_class_4.search(tab, 5);
        Assertions.assertTrue(index == 5);
    }






}
 */
