#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 2 && (n) <= 100000 &&
    \valid((aa) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (aa)[i] >= 1 && (aa)[i] <= (n) &&
    \forall integer i, j; 0 <= i < j < (n) ==> (aa)[i] != (aa)[j]);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *aa) {
    int count = 0;
    size_t i = 0;

    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
    (count) >= 0 && (count) <= (i) &&
    (((n)) >= 2 && ((n)) <= 100000 &&
    \valid(((aa)) + (0 .. ((n))-1)) &&
    \forall integer i; 0 <= i < ((n)) ==> ((aa))[i] >= 1 && ((aa))[i] <= ((n)) &&
    \forall integer i, j; 0 <= i < j < ((n)) ==> ((aa))[i] != ((aa))[j]));
        loop invariant i <= n;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 0 && i < n;
        if ((i + 1) == aa[i]) {
            count++;
        }
        i++;
    }

    if (count >= 2) {
        return count;
    } else {
        return 0;
    }
}
