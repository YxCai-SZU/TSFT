#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (a + b == c || a + c == b || b + c == a) {
        result = true;
        //@ assert ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    } else {
        //@ assert !((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        result = false;
    }
    
    return result;
}
