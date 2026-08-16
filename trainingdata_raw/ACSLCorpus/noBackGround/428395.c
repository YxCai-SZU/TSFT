#include <stdint.h>

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    uint32_t a;
    uint32_t b;
    
    a = 23;
    b = 67;
    
    //@ assert a == 23;
    //@ assert b == 67;
    
    return 0;
}
