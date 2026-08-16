#include <stdbool.h>
#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (m) && (m) <= 100 &&
      1 <= (x) && (x) <= (n) - 1);
  requires \valid(a + (0 .. m-1));
  requires (\forall integer i; 0 <= i < (m) ==> 
        1 <= (a)[i] && (a)[i] <= (n));
  requires (\forall integer i; 0 <= i < (m) ==> (a)[i] != (x));
  ensures \result <= m;
*/
uint32_t func(uint32_t n, uint32_t m, uint32_t x, int32_t* a) {
    uint32_t l = 0;
    uint32_t r = 0;
    uint32_t i = 0;
    uint32_t min_val;

    /*@
      loop invariant 0 <= i <= m;
      loop invariant l <= i;
      loop invariant r <= i;
      loop invariant l + r <= i;
      loop invariant \forall integer k; 0 <= k < i ==> a[k] != x;
      loop invariant (\forall integer i; 0 <= i < (m) ==> 
        1 <= (a)[i] && (a)[i] <= (n));
      loop invariant (1 <= (n) && (n) <= 100 &&
      1 <= (m) && (m) <= 100 &&
      1 <= (x) && (x) <= (n) - 1);
      loop assigns i, l, r;
    */
    while (i < m) {
        int32_t value = a[i];
        
        //@ assert value != x;
        
        if (value > x) {
            r = r + 1;
        }
        
        if (value < x) {
            l = l + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert l + r <= m;
    
    if (r < l) {
        min_val = r;
    } else {
        min_val = l;
    }
    
    //@ assert min_val == ((r) < (l) ? (r) : (l));
    //@ assert min_val <= m;
    
    return min_val;
}
