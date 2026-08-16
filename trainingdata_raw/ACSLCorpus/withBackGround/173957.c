#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 10000 && 0 <= a <= 1000;

    logic integer mod_500(integer n) = n % 500;

    lemma mod_range: \forall integer n; 1 <= n <= 10000 ==> 0 <= mod_500(n) < 500;
*/

/*@
    requires valid_params(n, a);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(int n, int a)
{
    int remainder;

    //@ assert valid_params(n, a);
    remainder = n;

    /*@
        loop invariant 0 <= remainder <= n;
        loop invariant remainder == n || remainder == n - 500 || remainder == n - 1000 || 
                     remainder == n - 1500 || remainder == n - 2000 || remainder == n - 2500 || 
                     remainder == n - 3000 || remainder == n - 3500 || remainder == n - 4000 || 
                     remainder == n - 4500 || remainder == n - 5000 || remainder == n - 5500 || 
                     remainder == n - 6000 || remainder == n - 6500 || remainder == n - 7000 || 
                     remainder == n - 7500 || remainder == n - 8000 || remainder == n - 8500 || 
                     remainder == n - 9000 || remainder == n - 9500 || remainder == n - 10000;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500)
    {
        remainder -= 500;
    }

    /*@
        loop invariant remainder < 500;
        loop invariant remainder == n - 500 * (n / 500) || 
                     remainder == n - 500 * (n / 500) + 500;
        loop assigns remainder;
        loop variant 500 + remainder;
    */
    while (remainder < 0)
    {
        remainder += 500;
    }

    //@ assert remainder == n % 500;
    //@ assert 0 <= remainder < 500;

    if (remainder <= a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
