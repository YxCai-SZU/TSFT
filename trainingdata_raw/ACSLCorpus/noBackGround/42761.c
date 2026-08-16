#include <stdbool.h>

/*@ requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b)) || ((a) == (b) && (b) == (c)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert a + b <= 18;
    
    result = (a == b + c || b == a + c || c == a + b) || (a == b && b == c);
    return result;
}
