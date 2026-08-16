#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_value;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert -199 <= a - b * 2 <= 100;
    
    if (0 > a - b * 2) {
        max_value = 0;
    } else {
        max_value = a - b * 2;
    }
    
    //@ assert max_value == a - b * 2 || max_value == 0;
    
    return max_value;
}
