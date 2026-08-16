#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate_sum(integer g, integer b) = 10 * g + b;

    lemma sum_mod_preserved:
        \forall integer s, t, m;
        s >= 0 && t >= 0 && m > 0 && s % m == t % m ==>
        (s % m == 0) == (t % m == 0);
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (calculate_sum(g, b) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    int sum;
    bool is_divisible;
    int temp_sum;

    //@ assert valid_range(r);
    //@ assert valid_range(g);
    //@ assert valid_range(b);
    
    sum = 10 * g + b;
    is_divisible = false;
    temp_sum = sum;
    
    /*@
        loop invariant 1 <= r <= 9;
        loop invariant 1 <= g <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant temp_sum >= 0;
        loop invariant temp_sum <= sum;
        loop invariant sum == calculate_sum(g, b);
        loop invariant sum % 4 == temp_sum % 4;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4)
    {
        temp_sum -= 4;
    }
    
    //@ assert sum % 4 == temp_sum % 4;
    
    if (temp_sum == 0)
    {
        is_divisible = true;
    }
    
    //@ assert (sum % 4 == 0) == (temp_sum == 0);
    //@ assert (sum % 4 == 0) == is_divisible;
    
    return is_divisible;
}
