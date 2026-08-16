#include <stdint.h>
#include <stdbool.h>

/*@
  requires N >= 1 && N <= 100000;
  requires \valid_read(hs + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> (((hs)[i]) >= 1 && ((hs)[i]) <= 1000000000));
  assigns \nothing;
  ensures \result <= N - 1;
*/
uint32_t func(uint32_t N, uint32_t *hs) {
    uint32_t cur_h;
    uint32_t cur_n;
    uint32_t res;
    uint32_t i;
    
    cur_h = hs[0];
    cur_n = 0;
    res = 0;
    i = 1;
    
    /*@
      loop invariant 1 <= i <= N;
      loop invariant 0 <= cur_n <= i - 1;
      loop invariant res <= i - 1;
      loop invariant (\forall integer i; 0 <= i < (N) ==> (((hs)[i]) >= 1 && ((hs)[i]) <= 1000000000));
      loop assigns i, cur_h, cur_n, res;
      loop variant N - i;
    */
    while (i < N) {
        uint32_t h;
        h = hs[i];
        
        if (cur_h < h) {
            //@ assert res <= i - 1;
            res = (res > cur_n) ? res : cur_n;
            cur_h = h;
            cur_n = 1;
        } else {
            cur_n += 1;
        }
        i += 1;
    }
    
    //@ assert res <= N - 1;
    res = (res > cur_n) ? res : cur_n;
    
    return res;
}
