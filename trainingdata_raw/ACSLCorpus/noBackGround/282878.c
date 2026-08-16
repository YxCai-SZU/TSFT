#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == true <==> ((c) >= (a) + (b) && (a) + (c) >= (b) && (b) + (c) >= (a));
    ensures \result == false <==> !((c) >= (a) + (b) && (a) + (c) >= (b) && (b) + (c) >= (a));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert a + b >= a;
    //@ assert a + c >= a;
    //@ assert b + c >= b;
    
    if (c < a + b || a + c < b || b + c < a) {
        result = false;
        //@ assert !((c) >= (a) + (b) && (a) + (c) >= (b) && (b) + (c) >= (a));
    } else {
        result = true;
        //@ assert ((c) >= (a) + (b) && (a) + (c) >= (b) && (b) + (c) >= (a));
    }
    
    return result;
}
