#include <stdbool.h>

/*@
    predicate condition_holds(integer n, integer m, integer a) =
        n + m - 1 >= a;
*/

/*@
    requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    requires 1 <= a <= 10000;
    ensures \result == true <==> (n + m - 1) >= a;
*/
bool func(long n, long m, long a)
{
    bool result;
    //@ ghost long n_val = n;
    //@ ghost long m_val = m;
    //@ ghost long a_val = a;
    
    if (n + m - 1 >= a)
    {
        //@ assert condition_holds(n_val, m_val, a_val);
        result = true;
    }
    else
    {
        //@ assert !condition_holds(n_val, m_val, a_val);
        result = false;
    }
    
    return result;
}
