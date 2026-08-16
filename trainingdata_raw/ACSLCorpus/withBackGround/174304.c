#include <stdbool.h>
/*@
    predicate is_valid_n(integer n) = 1 <= n <= 100000;

    logic integer manual_div_mod(integer n) = n / 2 + n % 2;

    lemma div_mod_property:
        \forall integer n; is_valid_n(n) ==> manual_div_mod(n) == n / 2 + n % 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == manual_div_mod(n);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int ans;
    unsigned int temp_n;
    
    ans = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= ans <= n / 2;
        loop invariant temp_n == n - 2 * ans;
        loop invariant is_valid_n(n);
        loop assigns ans, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        ans += 1;
        temp_n -= 2;
    }
    
    if (temp_n == 1)
    {
        //@ assert temp_n == 1;
        ans += 1;
    }
    
    //@ assert ans == manual_div_mod(n);
    return ans;
}
