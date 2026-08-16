#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000) && (1 <= (x) <= 10000) && (1 <= (y) <= 10000);
    ensures \result == (((n) * (x)) <= y);
    assigns \nothing;
*/
bool func(int n, int x, int y)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert (1 <= (n) <= 10000);
    //@ assert (1 <= (x) <= 10000);
    //@ assert (1 <= (y) <= 10000);
    
    //@ assert 1 <= ((n) * (x)) <= 100000000;
    
    result = (n * x) <= y;
    
    return result;
}
