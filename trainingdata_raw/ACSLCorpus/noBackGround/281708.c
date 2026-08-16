#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 1000000 &&
      (m) >= 1 && (m) <= 10000 &&
      (((n)) >= 1 &&
      \forall integer i; 0 <= i < ((n)) ==> (1) <= ((a))[i] && ((a))[i] <= (10000)) &&
      (((m)) >= 1 &&
      \forall integer i; 0 <= i < ((m)) ==> (1) <= ((b))[i] && ((b))[i] <= (10000)));
  assigns \nothing;
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= n;
*/
int func(int n, int m, int *a, int *b) {
    int prev = 0;
    size_t index = 0;
    int count = 0;

    /*@
      loop invariant 0 <= index <= (size_t)n;
      loop invariant 0 <= index <= (size_t)m;
      loop invariant count >= 0;
      loop invariant count <= (int)index;
      loop invariant ((n) >= 1 &&
      \forall integer i; 0 <= i < (n) ==> (1) <= (a)[i] && (a)[i] <= (10000));
      loop invariant ((m) >= 1 &&
      \forall integer i; 0 <= i < (m) ==> (1) <= (b)[i] && (b)[i] <= (10000));
      loop assigns index, count, prev;
      loop variant n - index;
    */
    while (index < (size_t)n && index < (size_t)m) {
        //@ assert 0 <= index < (size_t)n;
        //@ assert 0 <= index < (size_t)m;
        if (a[index] >= b[0]) {
            count += 1;
            prev = a[index];
        }
        index += 1;
    }
    return count;
}
