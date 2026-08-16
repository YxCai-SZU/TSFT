#include <limits.h>

/*@ predicate m_in_13_to_20(integer m) = 13 <= m <= 20;
    predicate m_in_1_to_12(integer m) = 1 <= m <= 12;
    predicate n_in_13_to_20(integer n) = 13 <= n <= 20;
    predicate n_in_1_to_12(integer n) = 1 <= n <= 12;
 */

/*@ requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (m >= 13 && m <= 20 ==> \result == 0);
    ensures (m <= 12 && n >= 13 ==> \result == 0);
    ensures (m <= 12 && n <= 12 ==> \result == m);
    ensures \result >= 0;
 */
int func(int n, int m)
{
    int ans;
    //@ assert 1 <= m <= 20;
    //@ assert 1 <= n <= 20;
    
    if (m >= 13 && m <= 20) {
        ans = 0;
        //@ assert ans == 0;
    } else if (m <= 12 && n >= 13) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        //@ assert m >= 1 && m <= 12;
        //@ assert n >= 1 && n <= 12;
        ans = m;
        //@ assert ans == m;
    }
    
    //@ assert ans >= 0;
    return ans;
}
