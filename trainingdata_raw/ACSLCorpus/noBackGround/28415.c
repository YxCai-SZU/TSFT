#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> ((((x)) % 100) * 21) < x;
    ensures \result == 0 ==> ((((x)) % 100) * 21) >= x;
*/
uint32_t func(uint32_t x) {
    uint32_t ans;
    
    //@ assert mod_bound: 0 <= x % 100 <= 99;
    //@ assert product_bound: (x % 100) * 21 <= 2100;
    
    if ((x % 100) * 21 < x) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans_property: ans == 0 || ans == 1;
    //@ assert ans_implies_1: ans == 1 ==> (x % 100) * 21 < x;
    //@ assert ans_implies_0: ans == 0 ==> (x % 100) * 21 >= x;
    
    return ans;
}
