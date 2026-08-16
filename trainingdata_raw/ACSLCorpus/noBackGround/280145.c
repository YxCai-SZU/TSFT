#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;
    
    // Proof of sum bounds
    //@ assert 0 <= a + b <= 200;
    
    result = (a + b >= c);
    //@ assert result == (a + b >= c);
    
    return result;
}
