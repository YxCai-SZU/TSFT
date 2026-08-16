#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
*/

/*@
    requires valid_range(n, m);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(n, m);
    
    result = (n == m);
    
    //@ assert result == (n == m);
    return result;
}

/*@
    lemma arithmetic_safe: 
        \forall integer n, m; valid_range(n, m) ==> n - m >= 0;
*/

int main(void)
{
    return 0;
}
