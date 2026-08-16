#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000 &&
        1 <= (m) && (m) <= 1000 &&
        0 <= (k) && (k) <= (n) * (m));
    ensures \result == (((n) * (m) - (k)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    // Variable declarations at scope top
    unsigned int product;
    unsigned int diff;
    bool result;

    //@ assert (1 <= (n) && (n) <= 1000 &&         1 <= (m) && (m) <= 1000 &&         0 <= (k) && (k) <= (n) * (m));
    
    product = n * m;
    //@ assert product <= 1000000;
    
    diff = product - k;
    //@ assert diff == ((n) * (m) - (k));
    
    result = (diff % 2 == 0);
    //@ assert result == (((n) * (m) - (k)) % 2 == 0);
    
    return result;
}
