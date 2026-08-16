#include <stdbool.h>

/*@ requires \valid(xs+(0..4));
    requires \forall integer i; 0 <= i < 5 ==> 
             xs[i] == i+1 || xs[i] == 0;
    requires \exists integer i; 0 <= i < 5 && xs[i] == 0;
    ensures 1 <= \result <= 5;
    ensures xs[\result-1] == 0;
    assigns \nothing;
 */
int func(int *xs) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\exists integer j; (0 <= (j) < 5) && (xs)[j] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (xs)[k] != 0);
        loop invariant \forall integer l; 0 <= l < 5 ==> 
                      xs[l] == l+1 || xs[l] == 0;
        loop assigns i;
        loop variant 5 - i;
     */
    while (i < 5) {
        //@ assert (0 <= (i) < 5);
        if (xs[i] == 0) {
            //@ assert xs[i] == 0;
            //@ assert (\forall integer k; 0 <= k < (i) ==> (xs)[k] != 0);
            return i + 1;
        }
        //@ assert xs[i] != 0;
        i = i + 1;
    }
    return -1;
}
