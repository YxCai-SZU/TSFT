#include <stdint.h>
#include <stdbool.h>

/*@
  requires ((n) >= 2 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
  ensures \result >= 0 && \result <= n-1;
  assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t *a) {
    uint64_t min;
    uint64_t count;
    uint64_t i;

    min = 1000000000;
    count = 0;
    i = 0;

    /*@
      loop invariant (0 <= (i) <= (n)-1 &&
      (((n)) >= 2 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 1000000000) &&
      (min) >= 1 && (min) <= 1000000000 &&
      (count) >= 0 && (count) <= (i));
      loop assigns i, min, count;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert (0 <= (i) <= (n)-1 &&       (((n)) >= 2 && ((n)) <= 200000 &&       \valid(((a)) + (0 .. ((n))-1)) &&       \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 1000000000) &&       (min) >= 1 && (min) <= 1000000000 &&       (count) >= 0 && (count) <= (i));
        if (min > a[i]) {
            min = a[i];
        }
        //@ assert min >= 1 && min <= 1000000000;
        if (min < a[i + 1]) {
            count += 1;
        }
        //@ assert count >= 0 && count <= i+1;
        i += 1;
    }
    return count;
}
