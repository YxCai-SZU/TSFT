#include <limits.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ lemma even_remainder_zero: 
      \forall integer n; n >= 0 ==> (n % 2 == 0) == (n - 2 * (n / 2) == 0); */

/*@ requires 1 <= n <= 1000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n % 2 == 0;
    ensures \result == 0 ==> n % 2 != 0;
    assigns \nothing;
 */
int func(long n)
{
    long n_abs;
    int is_even;
    long temp;
    int ans;
    
    if (n < 0) {
        n_abs = -n;
    } else {
        n_abs = n;
    }
    
    is_even = 0;
    temp = n_abs;
    
    /*@ loop invariant 0 <= temp <= n_abs;
        loop invariant temp % 2 == n_abs % 2;
        loop assigns temp;
        loop variant temp;
     */
    while (temp >= 2) {
        //@ assert temp % 2 == n_abs % 2;
        temp -= 2;
    }
    
    if (temp == 0) {
        is_even = 1;
    }
    
    if (is_even) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans == 1 ==> n_abs % 2 == 0;
    //@ assert ans == 0 ==> n_abs % 2 != 0;
    return ans;
}
