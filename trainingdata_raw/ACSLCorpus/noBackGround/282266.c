#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) <= (n) &&
        1 <= (b) && (b) <= (n));
    ensures \result == 1 <==> ((n) >= (b) && (a) <= (n) - (b) + 1);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    bool result;
    
    //@ assert ((n) >= (b) && (a) <= (n) - (b) + 1) ==> ((n) >= (b) && (a) <= (n) - (b) + 1);
    
    result = (n >= b && a <= n - b + 1);
    return result;
}
