#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int result;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert a * b <= 9;
    
    result = (a * b % 2 != 0);
    return result;
}
