#include <stdbool.h>

/*@ predicate both_even(integer n, integer m) = 
      n % 2 == 0 && m % 2 == 0; */

/*@ lemma sum_bound: 
      \forall integer n, m; 
      0 <= n && 0 <= m && n + m <= 100 ==> n + m <= 100; */

/*@ requires 0 <= n && 0 <= m && n + m <= 100;
    ensures \result == (n % 2 == 0 && m % 2 == 0);
    assigns \nothing;
 */
bool func(int n, int m)
{
    // Variable declarations at scope top
    bool result;
    
    if (n % 2 != 0 || m % 2 != 0) {
        //@ assert n % 2 != 0 || m % 2 != 0;
        return false;
    }

    if (n + m > 100) {
        //@ assert n + m > 100;
        return false;
    }

    //@ assert n % 2 == 0 && m % 2 == 0;
    return true;
}
