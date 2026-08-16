#include <stdint.h>

/*@
    requires (0 <= (n) && (n) < 10000);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result >= 0;
    ensures \result <= 4294967295;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n + 1 <= 10001;
    //@ assert n * (n + 1) <= 10000 * 10001;
    //@ assert n * (n + 1) / 2 <= (10000 * 10001) / 2;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    //@ assert n * (n + 1) <= 4294967295;
    
    return n * (n + 1) / 2;
}
