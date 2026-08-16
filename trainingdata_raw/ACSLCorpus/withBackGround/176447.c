#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@
    requires 1 <= n <= 100;
    ensures (is_even(n) ==> \result == 1) && (is_odd(n) ==> \result == 1);
    assigns \nothing;
*/
int func(int n)
{
    int ans = 1;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        ans = 1;
    } else {
        ans = 1;
    }
    
    //@ assert (is_even(n) ==> ans == 1) && (is_odd(n) ==> ans == 1);
    return ans;
}
