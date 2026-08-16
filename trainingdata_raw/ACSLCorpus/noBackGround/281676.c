#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    
    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100;
    
    if (x <= a + b && a <= x) {
        //@ assert ((x) <= (a) + (b) && (a) <= (x));
        result = true;
    } else {
        //@ assert !((x) <= (a) + (b) && (a) <= (x));
        result = false;
    }
    
    //@ assert result == (x <= a + b && a <= x);
    return result;
}
