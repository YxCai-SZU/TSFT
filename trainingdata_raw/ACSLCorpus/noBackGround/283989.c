#include <limits.h>
#include <stdbool.h>

/*@ requires (2 <= (k) && (k) <= (n) && (n) <= 100000);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
    requires \valid(a + (0 .. n-1));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int k, int *a) {
    int min_diff = INT_MAX;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n - k + 1;
        loop invariant (2 <= (k) && (k) <= (n) && (n) <= 100000);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
        loop invariant min_diff >= 0;
        loop invariant min_diff <= INT_MAX;
        loop invariant i > 0 ==> (\forall integer i; 0 <= i < (i) ==> 1 <= (a)[i] <= 1000000000);
        loop assigns i, min_diff;
        loop variant n - i;
    */
    while (i < n - k + 1) {
        int j = i + 1;
        
        /*@ loop invariant i + 1 <= j <= i + k;
            loop invariant (2 <= (k) && (k) <= (n) && (n) <= 100000);
            loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
            loop invariant min_diff >= 0;
            loop invariant min_diff <= INT_MAX;
            loop invariant i > 0 ==> (\forall integer i; 0 <= i < (i) ==> 1 <= (a)[i] <= 1000000000);
            loop assigns j, min_diff;
            loop variant i + k - j;
        */
        while (j < i + k) {
            //@ assert 1 <= a[i] <= 1000000000;
            //@ assert 1 <= a[j] <= 1000000000;
            
            int diff;
            if (a[i] > a[j]) {
                diff = a[i] - a[j];
            } else {
                diff = a[j] - a[i];
            }
            
            //@ assert diff >= 0;
            
            if (min_diff > diff) {
                min_diff = diff;
            }
            
            j++;
        }
        
        i++;
    }
    
    //@ assert min_diff >= 0;
    return min_diff;
}
