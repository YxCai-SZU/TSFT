#include <stddef.h>


size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t result = 0;
    
    //@ assert b * 2 <= 200;
    //@ assert a >= b * 2 || a < b * 2;
    
    if (a > b * 2) {
        //@ assert a > b * 2;
        result = a - b * 2;
    } else {
        //@ assert a <= b * 2;
        result = 0;
    }
    
    return result;
}
