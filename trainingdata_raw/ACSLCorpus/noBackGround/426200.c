#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000 &&
        0 <= (a) && (a) <= 1000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    // Variable declarations at scope top
    bool result;
    unsigned int mod_val;

    //@ assert 1 <= n && n <= 10000;
    //@ assert 0 <= a && a <= 1000;

    mod_val = n % 500;
    result = mod_val <= a;

    //@ assert result == (n % 500 <= a);
    return result;
}
