#include <limits.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == 2*a - 1 || \result == 2*b - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_value;
    int min_value;
    int result = 0;
    
    // Calculate max and min
    if (a > b) {
        max_value = a;
        min_value = b;
    } else {
        max_value = b;
        min_value = a;
    }
    
    //@ assert max_value == (((a) > (b)) ? (a) : (b));
    //@ assert min_value == (((a) < (b)) ? (a) : (b));
    
    // Main conditional logic
    if (max_value * 2 - 1 > max_value + min_value) {
        if (max_value * 2 - 1 == a + b) {
            result = a + b;
        } else {
            result = max_value * 2 - 1;
        }
    } else {
        result = max_value + min_value;
    }
    
    // Final verification property
    //@ assert result >= 0;
    
    return result;
}
