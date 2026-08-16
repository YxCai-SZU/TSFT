#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b * 2 % 2 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    //@ assert a * b <= 9;
    //@ assert a * b * 2 <= 18;
    
    result = (a * b * 2 % 2 == 0);
    return result;
}
