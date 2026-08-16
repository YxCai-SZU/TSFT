#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 100000 &&
        \valid((hs) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (hs)[i] >= 1 && (hs)[i] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n, int *hs) {
    int max = 0;
    int counter = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= counter <= index;
        loop invariant ((n) > 0 && (n) <= 100000 &&
        \valid((hs) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (hs)[i] >= 1 && (hs)[i] <= 1000000000);
        loop assigns max, counter, index;
        loop variant n - index;
    */
    while (index < n) {
        int h = hs[index];
        //@ assert h >= 1 && h <= 1000000000;
        if (max <= h) {
            max = h;
            counter += 1;
        }
        index += 1;
    }
    //@ assert counter >= 0;
    return counter;
}
