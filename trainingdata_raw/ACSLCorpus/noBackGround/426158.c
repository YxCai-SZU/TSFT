#include <stdint.h>
#include <stdbool.h>

/*@
  requires n > 0 && n < 0x80000000;
  requires \valid(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) < 0x80000000));
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int32_t func(uint32_t n, int32_t *numbers) {
    int32_t ans = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) < 0x80000000));
      loop invariant n > 0 && n < 0x80000000;
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int32_t x = numbers[i];
        
        //@ assert ((x) > 0 && (x) < 0x80000000);
        
        if ((i & 1) == 0 && (x & 1) == 1) {
            ans += 1;
        }
        
        i += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
