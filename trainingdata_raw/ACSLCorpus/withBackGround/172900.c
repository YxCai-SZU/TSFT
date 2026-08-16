#include <stdint.h>

/*@
    predicate valid_range(integer n) = 2 <= n <= 100;
    predicate valid_range_sub(integer n) = 1 <= n <= 99;
    predicate valid_product(integer p) = 1 <= p <= 9801;
*/

/*@
    requires valid_range(n) && valid_range(m);
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t max_val;
    int64_t min_val;
    int64_t result;

    //@ assert valid_range(n);
    //@ assert valid_range(m);
    
    max_val = (n > m) ? n : m;
    //@ assert max_val == ((n > m) ? n : m);
    
    min_val = (n < m) ? n : m;
    //@ assert min_val == ((n < m) ? n : m);
    
    //@ assert valid_range_sub(n - 1);
    //@ assert valid_range_sub(m - 1);
    
    //@ assert valid_product((n - 1) * (m - 1));
    
    result = (n - 1) * (m - 1);
    //@ assert result == (n - 1) * (m - 1);
    
    return result;
}
