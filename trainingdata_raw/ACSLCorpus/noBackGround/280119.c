#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (a)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= 198;
    assigns \nothing;
*/
int func(int *a) {
    int max_val;
    int min_val;
    int i;
    
    max_val = a[0];
    min_val = a[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (a)[i] <= 100);
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= a[j];
        loop invariant \forall integer j; 0 <= j < i ==> min_val <= a[j];
        loop invariant 1 <= max_val <= 100;
        loop invariant 1 <= min_val <= 100;
        loop invariant max_val >= min_val;
        loop assigns max_val, min_val, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
        if (a[i] < min_val) {
            min_val = a[i];
        }
        i++;
    }
    
    //@ assert max_val >= min_val;
    
    return max_val - min_val;
}
