#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (c - b <= d);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    long min_val;
    long max_val;
    bool condition;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    if (c < d) {
        max_val = d;
    } else {
        max_val = c;
    }
    
    //@ assert (1 <= (min_val) <= 10000);
    //@ assert (1 <= (max_val) <= 10000);
    
    if (c - b <= d) {
        condition = true;
    } else {
        condition = false;
    }
    
    //@ assert condition == (c - b <= d);
    return condition;
}
