#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires ((a) != (b) && (b) != (c) && (c) != (a));
    ensures \result == ((((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;
    
    //@ assert ((a) != (b) && (b) != (c) && (c) != (a));
    
    result = (a < c && c < b) || (b < c && c < a);
    
    //@ assert result == ((((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)) ? 1 : 0) == 1);
    
    return result;
}
