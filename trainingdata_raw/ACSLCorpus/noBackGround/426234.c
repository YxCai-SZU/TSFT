#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == 1 <==> (500 * (k) >= (x));
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool result;
    
    //@ assert 500 * k >= x ==> k * 500 >= x;
    result = (500 * k >= x);
    
    return result;
}
