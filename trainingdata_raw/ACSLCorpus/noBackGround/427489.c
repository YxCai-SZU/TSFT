#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 0 <= (a) <= 1000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    // Variable declarations at scope top
    bool result;
    unsigned int remainder;

    //@ assert 1 <= n <= 10000;
    //@ assert 0 <= a <= 1000;
    
    remainder = n % 500;
    
    //@ assert 0 <= remainder <= 499;
    
    result = (remainder <= a);
    
    //@ assert result == (n % 500 <= a);
    
    return result;
}
