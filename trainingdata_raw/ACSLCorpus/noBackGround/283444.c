#include <stdint.h>

/*@
  requires 1 <= A <= 20;
  requires 1 <= B <= 20;
  ensures (A <= 9 && B <= 9 ==> \result == 1);
  ensures (A > 9 || B > 9 ==> \result == 0);
*/
int32_t func(uint32_t A, uint32_t B) {
    int32_t ans;
    
    if (A <= 9 && B <= 9) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    return ans;
}
