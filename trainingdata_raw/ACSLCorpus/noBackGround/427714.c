#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
    (k) >= 1 && (k) <= 500 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (h)[j] >= 1 && (h)[j] <= 500);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
*/
long func(size_t n, size_t k, const long *h) {
    long res = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant res >= 0 && res <= i;
        loop invariant \valid(h + (0 .. n-1));
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        
        if (h[i] >= (long)k) {
            res += 1;
        }
        
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert res >= 0 && res <= n;
    return res;
}
