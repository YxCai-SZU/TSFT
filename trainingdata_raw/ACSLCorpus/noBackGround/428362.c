#include <stdbool.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;

    //@ assert 2 <= n <= 100;
    //@ assert 2 <= m <= 100;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 9801;

    result = (n - 1) * (m - 1);
    
    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
