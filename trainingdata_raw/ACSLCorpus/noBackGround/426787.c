#include <stdbool.h>
/*@
    requires ((len) >= 3 && (len) <= 10 &&
        \forall integer i; 0 <= i < (len) ==> (1 <= ((a)[i]) <= 100));
    ensures (1 <= (\result) <= 100);
    ensures \exists integer i; 0 <= i < len && \result == ((a)[(i)]);
*/
int func(int *a, int len) {
    int max;
    int i;
    //@ assert ((len) >= 3 && (len) <= 10 &&         \forall integer i; 0 <= i < (len) ==> (1 <= ((a)[i]) <= 100));
    max = a[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant ((len) >= 3 && (len) <= 10 &&
        \forall integer i; 0 <= i < (len) ==> (1 <= ((a)[i]) <= 100));
        loop invariant (1 <= (max) <= 100);
        loop invariant (\exists integer k; 0 <= k < (i) && (max) == (((a))[(k)]));
        loop assigns i, max;
    */
    while (i < len) {
        //@ assert (0 <= (i) < (len));
        if (a[i] > max) {
            max = a[i];
        }
        i = i + 1;
    }
    //@ assert (1 <= (max) <= 100);
    //@ assert (\exists integer k; 0 <= k < (len) && (max) == (((a))[(k)]));
    return max;
}
