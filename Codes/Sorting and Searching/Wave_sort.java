import java.util.ArrayList;
import java.util.Collections;

public class Wave_sort{

    public ArrayList<Integer> wave(ArrayList<Integer> A){

        /*
            Pen paper appraoch will tell that we can simply sort the array.
            And swap the second and odd index with previous even index
            swap(i,i-1) and move to next odd index
            i+=2;
        */

        Collections.sort(A);

        int n = A.size();
        int i = 1;

        while(i<n){

            Collections.swap(A, i, i-1);
            i+=2;
        }

        return A;

    }
}