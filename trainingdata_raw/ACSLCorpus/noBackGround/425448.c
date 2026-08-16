#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (a <= x && a + b >= x);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    bool left_inequality;
    bool right_inequality;
    bool result;
    
    // Implementing the left-inequality of the condition
    left_inequality = (a <= x);
    
    // Implementing the right-inequality of the condition
    //@ assert a + b <= 200;
    //@ assert a + b >= 0;
    right_inequality = (a + b >= x);
    
    // Combining the inequalities using 'and'
    result = left_inequality && right_inequality;
    
    //@ assert result == (a <= x && a + b >= x);
    
    return result;
}
