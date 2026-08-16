#include <stdbool.h>
#include <stddef.h>

/*@
  requires (3 <= (n) && (n) <= 100000);
  requires \valid(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) && ((h)[i]) <= 1000000000));
  ensures \result >= 0;
  ensures \result <= n - 2;
*/
int func(size_t n, const unsigned long long *h) {
    int c = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= n - 1;
      loop invariant c >= 0;
      loop invariant c <= i - 1;
      loop assigns c, i;
      loop variant n - i;
    */
    while (i < n - 1) {
        unsigned long long v = h[i];
        
        //@ assert (1 <= (h[i-1]) && (h[i-1]) <= 1000000000);
        if (h[i - 1] > v) {
            v = h[i - 1];
        }
        
        //@ assert (1 <= (h[i+1]) && (h[i+1]) <= 1000000000);
        if (h[i + 1] > v) {
            v = h[i + 1];
        }
        
        //@ assert (1 <= (h[i]) && (h[i]) <= 1000000000);
        if (h[i] == v) {
            c += 1;
        }
        
        i += 1;
    }
    
    return c;
}
