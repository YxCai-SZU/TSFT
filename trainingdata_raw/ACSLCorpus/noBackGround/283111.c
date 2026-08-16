#include <stdbool.h>

/*@
    requires ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100) && (1 <= ((x)) && ((x)) <= 200));
    ensures ((\result) == ((a) <= (x) && (x) <= ((a) + (b))));
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    long min_val;
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (x) && (x) <= 200);
    
    if (a + b < x) {
        min_val = a + b;
    } else {
        min_val = x;
    }
    
    //@ assert min_val == a + b || min_val == x;
    
    result = (a <= x) && (x <= min_val);
    
    //@ assert ((result) == ((a) <= (x) && (x) <= ((a) + (b))));
    return result;
}
