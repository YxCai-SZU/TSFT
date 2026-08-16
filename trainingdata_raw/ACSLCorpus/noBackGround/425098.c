#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n >= 0 && n <= 65535;
    //@ assert n + 1 >= 1 && n + 1 <= 65536;
    //@ assert n * (n + 1) >= 0 && n * (n + 1) <= 4294967295;
    //@ assert n * (n + 1) / 2 >= 0 && n * (n + 1) / 2 <= 2147483647;
    
    return n * (n + 1) / 2;
}
