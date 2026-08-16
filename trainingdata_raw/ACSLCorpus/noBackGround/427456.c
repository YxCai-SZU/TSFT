#include <stdbool.h>

/*@
    requires 1 <= n && n <= 10000;
    requires 0 <= a && a <= 100;
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int mod_result;
    bool result;
    
    //@ assert 1 <= n && n <= 10000;
    //@ assert 0 <= a && a <= 100;
    
    mod_result = n % 500;
    result = mod_result <= a;
    
    //@ assert result == (n % 500 <= a);
    return result;
}
