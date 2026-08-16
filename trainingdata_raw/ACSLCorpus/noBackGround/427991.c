#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == ((((n) % 10 == 5) || ((n) % 10 == 0) || ((n) % 10 == 7) || ((n) % 10 == 2) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    //@ assert 1 <= n && n <= 1000000000;
    
    bool result;
    result = (n % 10 == 5) || (n % 10 == 0) || (n % 10 == 7) || (n % 10 == 2);
    
    //@ assert result == ((((n) % 10 == 5) || ((n) % 10 == 0) || ((n) % 10 == 7) || ((n) % 10 == 2) ? 1 : 0) == 1);
    return result;
}
