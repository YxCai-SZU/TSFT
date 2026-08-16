#include <stdbool.h>

/*@
    requires a > -0x80000000 && a < 0x80000000;
    requires b > -0x80000000 && b < 0x80000000;
    requires c > -0x80000000 && c < 0x80000000;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c)
{
    bool is_increasing = true;
    
    //@ assert is_increasing == true;
    
    if (a >= b) {
        is_increasing = false;
        //@ assert is_increasing == false;
    }
    
    if (b >= c) {
        is_increasing = false;
        //@ assert is_increasing == false;
    }
    
    //@ assert is_increasing == true <==> ((a) < (b) && (b) < (c));
    
    return is_increasing;
}
