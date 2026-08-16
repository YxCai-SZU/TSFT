#include <stdbool.h>

/*@
  requires (1 <= (k) && (k) <= 100 &&
      1 <= (x) && (x) <= 100000);
  ensures \result == ((500 * (k)) >= x);
  assigns \nothing;
*/
bool func(long k, long x) {
    long r = 0;
    long product = 0;
    long i = 0;
    
    /*@
      loop invariant 0 <= r <= k;
      loop invariant 1 <= k <= 100;
      loop invariant 1 <= x <= 100000;
      loop invariant r <= 100;
      loop assigns r;
      loop variant k - r;
    */
    while (r < k) {
        //@ assert r < k;
        r = r + 1;
    }
    
    /*@
      loop invariant 0 <= i <= k;
      loop invariant product == (500 * (i));
      loop invariant i <= 100;
      loop assigns i, product;
      loop variant k - i;
    */
    while (i < k) {
        //@ assert i < k;
        product = product + 500;
        i = i + 1;
    }
    
    //@ assert product == (500 * (k));
    return product >= x;
}
