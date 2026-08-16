#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000 &&
        1 <= (m) && (m) <= 10000);
    ensures \result == ((((n) / 500) * 1000 + (((n) % 500) / 5) * 5) >= m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int n_500;
    unsigned int n_5;
    unsigned int sum;
    bool result;

    //@ assert (1 <= (n) && (n) <= 10000 &&         1 <= (m) && (m) <= 10000);
    
    n_500 = n / 500;
    n_5 = (n - n_500 * 500) / 5;
    sum = n_500 * 1000 + n_5 * 5;
    
    //@ assert sum == (((n) / 500) * 1000 + (((n) % 500) / 5) * 5);
    
    result = (sum >= m);
    
    //@ assert result == ((((n) / 500) * 1000 + (((n) % 500) / 5) * 5) >= m);
    return result;
}
