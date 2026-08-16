#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (int32_t)((a) * (b) + 1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t c;
    bool a_is_odd;
    bool b_is_odd;
    int32_t result;

    /*@ assert ((a) * (b) + 1) <= 100 * 100 + 1; */
    
    c = a * b + 1;
    a_is_odd = (a & 1) != 0;
    b_is_odd = (b & 1) != 0;
    
    /*@ assert c == ((a) * (b) + 1); */
    
    result = (int32_t)c;
    return result;
}
