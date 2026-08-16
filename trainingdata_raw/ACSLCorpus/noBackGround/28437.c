#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
    ensures \result == ((a * b * 2) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool is_even;
    bool result;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    //@ assert a * b <= 9;
    
    is_even = ((a * b * 2) % 2 == 0);
    //@ assert (a * b * 2) % 2 == ((a * b * 2) % 2);
    
    result = !is_even;
    return result;
}
