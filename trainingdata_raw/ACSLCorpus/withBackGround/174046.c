#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v && v <= 10;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool ans;
    //@ assert a + b <= 20;
    //@ assert b + c <= 20;
    //@ assert c + a <= 20;
    //@ assert a + b >= 2;
    //@ assert b + c >= 2;
    //@ assert c + a >= 2;
    
    if (a + b == c || b + c == a || c + a == b)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    
    //@ assert a + b <= 20;
    //@ assert b + c <= 20;
    //@ assert c + a <= 20;
    //@ assert a + b == c || b + c == a || c + a == b || ans == false;
    
    return ans;
}
