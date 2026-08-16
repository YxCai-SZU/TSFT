#include <stdint.h>

/*@
    requires (1 <= (a) <= 100000);
    ensures ((\result) == 0 || (\result) == 1);
    assigns \nothing;
*/
int32_t func(uint32_t a) {
    uint32_t num;
    uint32_t remained;
    int32_t ans;
    uint32_t i;
    
    num = a / 100;
    remained = a % 100;
    ans = 0;
    
    if (remained >= 5 && remained != 100) {
        ans = 1;
    } else if (remained == 0) {
        ans = 0;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= num;
        loop invariant (1 <= (a) <= 100000);
        loop invariant ((ans) == 0 || (ans) == 1);
        loop assigns i, ans;
        loop variant num - i;
    */
    while (i < num) {
        //@ assert ((ans) == 0 || (ans) == 1);
        if (remained + i * 5 >= 100) {
            ans = 1;
            break;
        }
        i = i + 1;
    }
    
    //@ assert ((ans) == 0 || (ans) == 1);
    return ans;
}
