#include <stddef.h>
#include <stdint.h>

/*@
  requires (2 <= (n) && (n) <= 100000);
  requires n == len;
  requires \forall integer i; 0 <= i < n ==> (1 <= (h[i]) && (h[i]) <= 10000);
  requires (1 <= (k) && (k) <= 500);
  ensures \result >= 0;
  ensures \result <= n;
*/
int64_t func(size_t n, const int64_t* h, size_t len, int64_t k) {
    int64_t cur_h = 0;
    int64_t res = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant 0 <= res <= index;
      loop invariant n == len;
      loop invariant (2 <= (n) && (n) <= 100000);
      loop invariant (1 <= (k) && (k) <= 500);
      loop invariant \forall integer i; 0 <= i < len ==> (1 <= (h[i]) && (h[i]) <= 10000);
      loop assigns cur_h, res, index;
    */
    while (index < len) {
        int64_t hh = h[index];
        if (hh >= cur_h) {
            //@ assert hh >= cur_h;
            res += 1;
            cur_h = hh;
        }
        index += 1;
    }
    return res;
}
