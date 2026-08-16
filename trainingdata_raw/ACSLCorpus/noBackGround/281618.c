#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires 1 <= k <= 10000;
  requires 1 <= t <= 100;
  requires \valid(a + (0 .. t-1));
  requires ((t) > 0 &&
      \forall size_t i; 0 <= i < (t) ==> 1 <= (a)[i] <= 100);
  ensures \result >= 0;
*/
int64_t func(int64_t k, size_t t, int64_t* a) {
    int64_t max;
    size_t i;
    
    max = a[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= t;
      loop invariant ((t) > 0 &&
      \forall size_t i; 0 <= i < (t) ==> 1 <= (a)[i] <= 100);
      loop invariant 1 <= max <= 100;
      loop invariant (\forall size_t j; 0 <= j < (i) ==> (max) >= (a)[j]);
      loop assigns i, max;
    */
    while (i < t) {
        //@ assert 0 <= i < t;
        if (a[i] > max) {
            max = a[i];
        }
        i++;
    }
    
    //@ assert (\forall size_t j; 0 <= j < (t) ==> (max) >= (a)[j]);
    
    if (max - (k - max) <= 1) {
        return 0;
    } else {
        return max - (k - max) - 1;
    }
}
