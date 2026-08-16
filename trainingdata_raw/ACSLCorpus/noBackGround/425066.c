#include <stdint.h>

/*@
    requires (1 <= (X) <= 205) && (1 <= (Y) <= 205);
    ensures \result == ((X) * (Y) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t X, uint32_t Y) {
    uint32_t money;
    
    //@ assert X * Y <= 205 * 205;
    
    money = X * Y / 2;
    
    //@ assert money == ((X) * (Y) / 2);
    
    return money;
}
