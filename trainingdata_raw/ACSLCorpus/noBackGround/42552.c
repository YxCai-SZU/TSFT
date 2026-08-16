#include <stdbool.h>

/*@ requires 0 <= a <= 10000;
    ensures \result == (a >= 9000);
    assigns \nothing;
 */
bool func(int a)
{
    bool is_greater_or_equal;
    
    //@ assert 0 <= a <= 10000;
    
    if (a >= 9000) {
        is_greater_or_equal = true;
        //@ assert is_greater_or_equal == (a >= 9000);
    } else {
        is_greater_or_equal = false;
        //@ assert is_greater_or_equal == (a >= 9000);
    }
    
    return is_greater_or_equal;
}
