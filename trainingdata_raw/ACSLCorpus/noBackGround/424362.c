#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= k <= n <= 100000;
    requires ((n) >= 2 && (n) <= 100000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, size_t k, int *a) {
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n)-1 &&
      (l) <= (i) &&
      (r) <= (i) &&
      (l) + (r) <= (i) &&
      (((n)) >= 2 && ((n)) <= 100000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= ((n)) &&
      \forall integer i, j; 0 <= i < j < ((n)) ==> ((a))[i] != ((a))[j]));
        loop invariant i < n;
        loop assigns i, l, r;
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        if (a[i] + 1 < a[i + 1]) {
            r += 1;
        } else {
            l += 1;
        }
        i += 1;
        
        //@ assert l + r <= i;
    }
    
    size_t min_val = (l < r) ? l : r;
    
    //@ assert 0 <= min_val < n;
    //@ assert 1 <= n - min_val <= n;
    
    return (int)(n - min_val);
}
