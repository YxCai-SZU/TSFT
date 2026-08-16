#include <stdbool.h>

/*@
    predicate is_even_mod(integer k) = k % 2 == 0;
    predicate is_multiple_of_5_mod(integer k) = k % 5 == 0;
    logic integer mod_2(integer k) = k % 2;
    logic integer mod_5(integer k) = k % 5;
    lemma mod_2_loop: \forall integer k, t; 0 <= t <= k && t % 2 == k % 2 ==> t % 2 == k % 2;
    lemma mod_5_loop: \forall integer k, t; 0 <= t <= k && t % 5 == k % 5 ==> t % 5 == k % 5;
*/

/*@
    requires 1 <= k <= 100;
    ensures \result == (k % 2 == 0 || k % 5 == 0);
*/
bool func(int k)
{
    bool is_even;
    bool is_multiple_of_5;
    int temp_k;

    is_even = false;
    temp_k = k;
    /*@
        loop invariant 1 <= k <= 100;
        loop invariant 0 <= temp_k <= k;
        loop invariant temp_k % 2 == k % 2;
        loop assigns temp_k;
    */
    while (temp_k >= 2)
    {
        temp_k -= 2;
    }
    if (temp_k == 0)
    {
        is_even = true;
    }

    is_multiple_of_5 = false;
    temp_k = k;
    /*@
        loop invariant 1 <= k <= 100;
        loop invariant 0 <= temp_k <= k;
        loop invariant temp_k % 5 == k % 5;
        loop assigns temp_k;
    */
    while (temp_k >= 5)
    {
        temp_k -= 5;
    }
    if (temp_k == 0)
    {
        is_multiple_of_5 = true;
    }

    if (is_even || is_multiple_of_5)
    {
        return true;
    }
    else
    {
        return false;
    }
}
