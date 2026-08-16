#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 10000);
    ensures \result == ((((a) + (b) >= (c)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool is_enough = false;
    
    //@ assert (1 <= (a) && (a) <= 5000 &&         1 <= (b) && (b) <= 5000 &&         1 <= (c) && (c) <= 10000);
    
    if (a + b >= c)
    {
        is_enough = true;
    }
    
    //@ assert is_enough == ((((a) + (b) >= (c)) ? 1 : 0) == 1);
    
    return is_enough;
}
