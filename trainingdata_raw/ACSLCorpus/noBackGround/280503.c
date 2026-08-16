#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == (a + b == c || b + c == a || a + c == b);
    assigns \nothing;
*/
bool can_distribute_equally(int a, int b, int c)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    bool result;
    result = (a + b == c) || (b + c == a) || (a + c == b);
    
    //@ assert result == (a + b == c || b + c == a || a + c == b);
    return result;
}
