#include <stddef.h>
#include <stdint.h>

/*@
  requires (1 <= (n) <= 200000);
  requires \valid(v + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 1000000));
  ensures -1 <= \result <= (int)n;
  assigns \nothing;
*/
int32_t func(size_t n, int32_t *v) {
    uint32_t ok_cnt = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ok_cnt <= (uint32_t)i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 1000000));
      loop assigns i, ok_cnt;
      loop variant n - i;
    */
    while (i < n) {
        int32_t value = v[i];
        //@ assert (1 <= (value) <= 1000000);
        if ((value & 1) == 1 && ((value >> 1) & 1) == 0) {
            ok_cnt += 1;
        }
        i += 1;
    }
    
    if (ok_cnt >= 3) {
        return 0;
    }
    
    uint32_t ng_cnt = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ng_cnt <= (uint32_t)i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 1000000));
      loop assigns i, ng_cnt;
      loop variant n - i;
    */
    while (i < n) {
        int32_t value = v[i];
        //@ assert (1 <= (value) <= 1000000);
        if ((value & 1) == 1 && ((value >> 1) & 1) == 1) {
            ng_cnt += 1;
        }
        i += 1;
    }
    
    if (ng_cnt >= 3) {
        return 1;
    }
    
    return -1;
}
