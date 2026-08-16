#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer j; 0 <= j < (n) ==> (1 <= ((l)[j]) <= 100));
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int count_possible_heights(int *l, int n) {
    int count = 0;
    int i = 0;
    /*@
        loop invariant (0 <= (i) <= (n));
        loop invariant ((count) >= 0 && (count) <= (i));
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \forall integer j; 0 <= j < (n) ==> (1 <= ((l)[j]) <= 100));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int h = l[i];
        //@ assert (1 <= (h) <= 100);
        if (h >= 0) {
            count += 1;
        }
        i += 1;
    }
    //@ assert ((count) >= 0 && (count) <= (n));
    return count;
}
