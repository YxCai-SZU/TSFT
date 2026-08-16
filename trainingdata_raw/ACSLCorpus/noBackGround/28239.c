#include <limits.h>

/*@ requires (2 <= (n) && (n) <= 100 &&
      \valid((w) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (w)[i] && (w)[i] <= 100);
    ensures \result >= 0;
*/
int func(int n, int *w) {
    int sum = 0;
    int i = 0;
    int min = INT_MAX;
    int j = 0;
    int left_sum = 0;
    int right_sum = 0;
    int k = 0;
    int diff = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ((sum) >= 0 && (sum) <= (i) * 100);
        loop invariant (2 <= (n) && (n) <= 100 &&
      \valid((w) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (w)[i] && (w)[i] <= 100);
        loop assigns sum, i;
    */
    while (i < n) {
        //@ assert 1 <= w[i] && w[i] <= 100;
        sum += w[i];
        i++;
    }
    
    /*@ loop invariant 0 <= j <= n;
        loop invariant min >= 0;
        loop invariant (2 <= (n) && (n) <= 100 &&
      \valid((w) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (w)[i] && (w)[i] <= 100);
        loop assigns j, min, left_sum, right_sum, k, diff;
    */
    while (j < n) {
        left_sum = 0;
        k = 0;
        
        /*@ loop invariant 0 <= k <= j+1;
            loop invariant ((left_sum) >= 0 && (left_sum) <= (k) * 100);
            loop invariant (2 <= (n) && (n) <= 100 &&
      \valid((w) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (w)[i] && (w)[i] <= 100);
            loop invariant j < n;
            loop assigns left_sum, k;
        */
        while (k <= j) {
            //@ assert 1 <= w[k] && w[k] <= 100;
            left_sum += w[k];
            k++;
        }
        
        right_sum = 0;
        k = j + 1;
        
        /*@ loop invariant j+1 <= k <= n;
            loop invariant ((right_sum) >= 0 && (right_sum) <= (k - (j+1)) * 100);
            loop invariant (2 <= (n) && (n) <= 100 &&
      \valid((w) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (w)[i] && (w)[i] <= 100);
            loop invariant j < n;
            loop assigns right_sum, k;
        */
        while (k < n) {
            //@ assert 1 <= w[k] && w[k] <= 100;
            right_sum += w[k];
            k++;
        }
        
        diff = left_sum - right_sum;
        if (diff < 0) {
            diff = -diff;
        }
        
        if (diff < min) {
            min = diff;
        }
        j++;
    }
    
    //@ assert min >= 0;
    return min;
}
