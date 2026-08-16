#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
*/
bool func(int a, int b)
{
    bool is_even_var = false;
    
    //@ assert a % 2 == 0 || b % 2 == 0 || !is_even_var;
    
    if (a % 2 == 0 || b % 2 == 0)
    {
        is_even_var = true;
    }
    
    //@ assert !(a % 2 == 0) && !(b % 2 == 0) || is_even_var;
    
    return is_even_var;
}
