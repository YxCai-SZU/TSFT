#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool a_is_even;
    bool b_is_even;
    bool is_even;
    
    a_is_even = (a % 2 == 0);
    b_is_even = (b % 2 == 0);
    is_even = a_is_even || b_is_even;
    
    //@ assert is_even == (a % 2 == 0 || b % 2 == 0);
    
    return is_even;
}
