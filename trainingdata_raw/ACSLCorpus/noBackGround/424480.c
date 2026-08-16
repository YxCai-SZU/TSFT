#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a * 100 / 2) >= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int a_scaled;
    int half_scaled;
    bool result;

    a_scaled = a * 100;
    half_scaled = a_scaled / 2;
    
    //@ assert half_scaled == (a * 100 / 2);
    
    result = half_scaled >= b;
    return result;
}
