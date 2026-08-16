#include <stdint.h>

/*@
    requires ((length) <= 0xFFFFFFFFFFFFFFFF / (width));
    ensures \result == ((length) * (width));
*/
uint64_t area_rectangle(uint64_t length, uint64_t width)
{
    //@ assert ((length) <= 0xFFFFFFFFFFFFFFFF / (width));
    
    uint64_t area;
    
    //@ assert ((length) * (width)) <= 0xFFFFFFFFFFFFFFFF;
    
    area = length * width;
    
    //@ assert area == ((length) * (width));
    
    return area;
}
