#include <stdbool.h>

/*@
    requires a < 0x80000000 && b < 0x80000000 && c < 0x80000000 && 
             d < 0x80000000 && e < 0x80000000 && k < 0x80000000;
    ensures \result == true <==> ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e) && (e) - (a) <= (k));
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    bool result;
    
    //@ assert a < 0x80000000 && b < 0x80000000 && c < 0x80000000;
    //@ assert d < 0x80000000 && e < 0x80000000 && k < 0x80000000;
    
    if (a <= b && b <= c && c <= d && d <= e && e - a <= k) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
