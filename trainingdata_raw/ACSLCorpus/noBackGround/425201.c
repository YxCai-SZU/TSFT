#include <stdint.h>
#include <stdbool.h>

/*@
  requires n >= 1 && n <= 100000;
  requires \valid(a + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) && ((a)[i]) <= 1000000000));
  ensures \result >= 0;
  assigns \nothing;
*/
int32_t func(uint32_t n, int32_t *a) {
    uint32_t num = 0;
    int32_t cnt = 0;
    uint32_t index = 0;

    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= cnt <= (int32_t)index;
      loop invariant num <= index;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) && ((a)[i]) <= 1000000000));
      loop assigns index, cnt, num;
      loop variant n - index;
    */
    while (index < n) {
        int32_t ai = a[index];
        
        //@ assert (1 <= (ai) && (ai) <= 1000000000);
        
        if (ai & 1) {
            cnt += 1;
        } else {
            num += 1;
        }
        
        index += 1;
    }
    
    //@ assert cnt >= 0;
    return cnt >= 0 ? cnt : -cnt;
}
