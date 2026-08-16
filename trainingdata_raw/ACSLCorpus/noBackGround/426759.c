#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 200000;
    requires \valid(a + (0..n-1));
    requires ((n) > 0 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> (((a)[i]) > 0 && ((a)[i]) <= 1000000000));
    ensures \result >= 0 && \result <= 1000000000;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int hi = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ((hi) >= 0 && (hi) <= 1000000000 &&
        ((index) > 0 ==> \forall integer j; 0 <= j < (index) ==> (hi) >= (a)[j]));
        loop invariant ((n) > 0 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> (((a)[i]) > 0 && ((a)[i]) <= 1000000000));
        loop assigns hi, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert ((n) > 0 && (n) <= 200000 &&         \forall integer i; 0 <= i < (n) ==> (((a)[i]) > 0 && ((a)[i]) <= 1000000000));
        //@ assert ((hi) >= 0 && (hi) <= 1000000000 &&         ((index) > 0 ==> \forall integer j; 0 <= j < (index) ==> (hi) >= (a)[j]));
        if (hi < a[index]) {
            hi = a[index];
        }
        index++;
    }
    //@ assert ((hi) >= 0 && (hi) <= 1000000000 &&         (((n)) > 0 ==> \forall integer j; 0 <= j < ((n)) ==> (hi) >= (a)[j]));
    return hi;
}
