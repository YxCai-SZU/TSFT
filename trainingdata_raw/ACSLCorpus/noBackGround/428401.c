#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (n * n % 2 != 0);
    assigns \nothing;
*/
bool func(int n)
{
    // Variable declarations at top of scope
    bool result;
    int square;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    
    square = n * n;
    result = (square % 2) != 0;
    
    return result;
}
