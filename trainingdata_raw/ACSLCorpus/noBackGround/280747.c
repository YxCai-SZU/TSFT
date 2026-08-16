#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000 &&
        1 <= (m) && (m) <= 1000 &&
        1 <= (k) && (k) <= 1000 &&
        (n) <= (m) * (k));
    ensures \result == (k * m >= n);
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    // Variable declarations at top of scope
    bool result;
    int product;

    //@ assert 1 <= n && n <= 1000;
    //@ assert 1 <= m && m <= 1000;
    //@ assert 1 <= k && k <= 1000;
    //@ assert n <= m * k;

    product = k * m;
    
    //@ assert product <= 1000000;
    
    result = (product >= n);
    
    //@ assert result == (k * m >= n);
    
    return result;
}
