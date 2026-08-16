#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000);
    requires (1 <= (b) <= 5000);
    requires (1 <= (c) <= 5000);
    ensures \result == true <==> ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a <= 5000;
    //@ assert 1 <= b <= 5000;
    //@ assert 1 <= c <= 5000;
    
    result = (a + b == c) || (a + c == b) || (b + c == a);
    
    return result;
}
