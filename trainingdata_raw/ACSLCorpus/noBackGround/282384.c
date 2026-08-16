#include <stdbool.h>

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= x <= 1000000000;
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool is_possible_to_have_x_cats(long long a, long long b, long long x)
{
    //@ assert 0 <= a <= 1000000000;
    //@ assert 0 <= b <= 1000000000;
    //@ assert 0 <= x <= 1000000000;
    
    bool result;
    
    if (a <= x && a + b >= x) {
        //@ assert ((a) <= (x) && (a) + (b) >= (x));
        result = true;
    } else {
        //@ assert !((a) <= (x) && (a) + (b) >= (x));
        result = false;
    }
    
    //@ assert result == (a <= x && a + b >= x);
    return result;
}
