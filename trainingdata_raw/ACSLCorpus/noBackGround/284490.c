#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires \forall integer j; 0 <= j < n ==> a[j] > 0 && a[j] <= 1000000000;
    assigns \nothing;
    ensures \result <= n;
*/
unsigned int func(size_t n, unsigned int *a) {
    unsigned int counter = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= n;
        loop invariant counter <= i;
        loop invariant ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (a)[j] > 0 && (a)[j] <= 1000000000);
        loop assigns i, counter;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] & 1) {
            counter++;
        }
        i++;
    }

    //@ assert counter <= n;
    return counter;
}
