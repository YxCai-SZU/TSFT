#include <stdbool.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(unsigned n, unsigned *a) {
    int sum = 0;
    unsigned i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (sum) >= 0 &&
        (sum) <= (int)(i) &&
        (((n)) >= 1 && ((n)) <= 100 &&
        \valid(((a)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 100) &&
        \forall integer k; 0 <= k < (i) ==> (((a)[k] & 1) == 1) ==> (sum) >= 1);
        loop assigns i, sum;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if ((a[i] & 1) == 1) {
            sum += 1;
        }
        i += 1;
    }
    
    //@ assert sum >= 0 && sum <= (int)n;
    return sum;
}
