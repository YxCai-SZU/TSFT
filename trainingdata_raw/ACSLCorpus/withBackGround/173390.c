/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer compute_n(integer r, integer g, integer b) = 100 * r + 10 * g + b;

    lemma mod_preservation:
        \forall integer n, integer temp_n;
        n >= 0 && temp_n >= 0 && n % 4 == temp_n % 4 && temp_n < 4 ==> n % 4 == temp_n;
*/

#include <stdbool.h>

/*@
    requires valid_range(r);
    requires valid_range(g);
    requires valid_range(b);
    ensures \result == (compute_n(r, g, b) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    int n;
    bool is_divisible;
    int temp_n;

    n = 100 * r + 10 * g + b;
    is_divisible = false;
    temp_n = n;

    /*@
        loop invariant 1 <= r <= 9;
        loop invariant 1 <= g <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant 0 <= temp_n <= n;
        loop invariant n % 4 == temp_n % 4;
        loop assigns temp_n;
    */
    while (temp_n >= 4)
    {
        temp_n -= 4;
    }

    //@ assert n % 4 == temp_n;
    
    if (temp_n == 0)
    {
        is_divisible = true;
    }

    return is_divisible;
}
