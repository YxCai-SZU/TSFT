#include <stdbool.h>

/*@
    requires 1 <= n <= 1000;
    requires 1 <= m <= 1000;
    requires 0 <= k <= n * m;
    ensures \result == true <==> (n * m - k) % 2 == 0;
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    unsigned int n_u32;
    unsigned int m_u32;
    unsigned int k_u32;
    unsigned int product;
    unsigned int difference;
    bool result;

    n_u32 = (unsigned int)n;
    m_u32 = (unsigned int)m;
    k_u32 = (unsigned int)k;

    //@ assert (1 <= (n) <= 1000 && 1 <= (m) <= 1000 ==> (n) * (m) <= 1000000);
    product = n_u32 * m_u32;
    
    //@ assert product >= k_u32;
    difference = product - k_u32;
    
    //@ assert difference <= 1000000;
    //@ assert difference == (unsigned int)(n * m - k);

    if (difference % 2 == 0) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
