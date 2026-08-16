#include <stdbool.h>
#include <stdint.h>

/*@
    requires 0 <= a <= 0xffffffff;
    requires 0 <= b <= 0xffffffff;
    ensures \result == ((a & b) != 0);
 */
bool func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t c;
    bool result;

    //@ assert 0 <= a <= 0xffffffff;
    //@ assert 0 <= b <= 0xffffffff;
    
    c = a & b;
    
    //@ assert c == (a & b);
    
    result = (c != 0);
    //@ assert result == ((a & b) != 0);
    return result;
}
