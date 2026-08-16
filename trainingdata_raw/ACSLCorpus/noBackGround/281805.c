#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (int)(n));
    ensures \result >= 0;
    ensures \result <= (int)n;
*/
int func(size_t n, int *a) {
    int count = 0;
    int p = 1;
    size_t index = 0;

    /*@ loop invariant (0 <= (index) && (index) <= (n) &&
      0 <= (count) && (count) <= (int)(index) &&
      1 <= (p) && (p) <= (int)(index) + 1 &&
      (((n)) >= 2 && ((n)) <= 100000 &&
      \forall size_t i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= (int)((n))));
        loop assigns index, count, p;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert (0 <= (index) && (index) <= (n) &&       0 <= (count) && (count) <= (int)(index) &&       1 <= (p) && (p) <= (int)(index) + 1 &&       (((n)) >= 2 && ((n)) <= 100000 &&       \forall size_t i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= (int)((n))));
        int value = a[index];
        if (value == p) {
            p = p + 1;
        } else {
            count = count + 1;
        }
        index = index + 1;
        //@ assert (0 <= (index) && (index) <= (n) &&       0 <= (count) && (count) <= (int)(index) &&       1 <= (p) && (p) <= (int)(index) + 1 &&       (((n)) >= 2 && ((n)) <= 100000 &&       \forall size_t i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= (int)((n))));
    }
    //@ assert count >= 0;
    //@ assert count <= (int)n;
    return count;
}
