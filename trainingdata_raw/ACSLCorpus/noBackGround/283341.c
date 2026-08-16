#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    ensures \result == 0 || \result == 1 || \result == 2 || \result == 3 || \result == 4 ||
            \result == 5 || \result == 6 || \result == 7 || \result == 8 || \result == 9;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    result = 1;
    
    if (a > 3) { result = 2; }
    if (a > 6) { result = 3; }
    if (a > 9) { result = 4; }
    if (a > 12) { result = 5; }
    if (a > 15) { result = 6; }
    if (a > 18) { result = 7; }
    if (a > 21) { result = 8; }
    if (a > 24) { result = 9; }
    
    //@ assert 1 <= result <= 9;
    //@ assert ((result) == 0 || (result) == 1 || (result) == 2 || (result) == 3 || (result) == 4 ||         (result) == 5 || (result) == 6 || (result) == 7 || (result) == 8 || (result) == 9);
    
    return result;
}
