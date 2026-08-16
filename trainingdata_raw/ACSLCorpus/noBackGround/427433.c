#include <stdint.h>

/*@
    requires 1 <= k <= 99999;
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(uint32_t k) {
    int32_t money;
    uint32_t i;
    uint32_t j;
    
    money = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= k + 1;
        loop invariant ((money) >= 0 && (money) <= ((i) - 1) * 7);
        loop assigns money, i;
        loop variant k - i + 1;
    */
    while (i <= k) {
        //@ assert money >= 0;
        money += 7;
        i += 1;
    }
    
    j = 0;
    
    /*@
        loop invariant 0 <= j <= k;
        loop invariant ((money) >= 0 && (money) <= ((k) * 10 + (j) * 7));
        loop assigns money, j;
        loop variant k - j;
    */
    while (j < k) {
        //@ assert money >= 0;
        if (j + 1 < k && (j + 1) * 8 <= k * 10) {
            money += 7;
        } else {
            break;
        }
        j += 1;
    }
    
    //@ assert money >= 0;
    return money;
}
