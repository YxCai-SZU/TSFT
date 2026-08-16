#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 2 && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *a) {
    int count = 0;
    int x = 0;
    size_t index = 0;

    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
      (count) >= 0 && (count) <= (index) &&
      (x) >= 0 &&
      (((n)) >= 2 && ((n)) <= 100000 &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 1000000000));
        loop assigns count, x, index;
        loop variant n - index;
    */
    while (index < (size_t)n && x >= 0) {
        //@ assert index < n;
        x = a[index] - x;
        if (x < 0) {
            x = -x;
        }
        count += 1;
        index += 1;
    }

    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
