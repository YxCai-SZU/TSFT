#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
  ensures \result >= 0;
  ensures \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t num = 1;
    size_t i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (count) <= (int)(i) &&
      (num) <= (i) + 1 &&
      \forall size_t j; 0 <= j < (i) ==> (a)[j] > 0 && (a)[j] <= 1000 &&
      (((n)) > 0 && ((n)) <= 100 &&
      \forall size_t i; 0 <= i < ((n)) ==> ((a))[i] > 0 && ((a))[i] <= 1000));
      loop assigns i, count, num;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (num == (size_t)a[i]) {
            count += 1;
            num += 1;
        }
        i += 1;
    }
    //@ assert i == n;
    return count;
}
