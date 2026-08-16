#include <stdbool.h>

/*@
    predicate is_divisible_by_3(integer x) = x % 3 == 0;
*/

/*@
    lemma mod_preservation:
        \forall integer a, b;
            0 <= b <= a ==>
            (a - b) % 3 == (a % 3 - b % 3 + 3) % 3;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> 
            (is_divisible_by_3(a) || 
             is_divisible_by_3(b) || 
             is_divisible_by_3(a + b));
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result = false;
    bool is_a_divisible_by_3 = false;
    bool is_b_divisible_by_3 = false;
    bool is_a_plus_b_divisible_by_3 = false;
    int temp_a = a;
    int temp_b = b;
    int sum = a + b;
    int temp_sum = sum;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant temp_a >= 0;
        loop invariant temp_a <= a;
        loop invariant temp_a % 3 == a % 3;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 3)
    {
        //@ assert temp_a % 3 == a % 3;
        temp_a -= 3;
    }
    if (temp_a == 0)
    {
        is_a_divisible_by_3 = true;
    }

    /*@
        loop invariant 1 <= b <= 100;
        loop invariant temp_b >= 0;
        loop invariant temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 3)
    {
        //@ assert temp_b % 3 == b % 3;
        temp_b -= 3;
    }
    if (temp_b == 0)
    {
        is_b_divisible_by_3 = true;
    }

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_sum >= 0;
        loop invariant temp_sum <= sum;
        loop invariant temp_sum % 3 == sum % 3;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 3)
    {
        //@ assert temp_sum % 3 == sum % 3;
        temp_sum -= 3;
    }
    if (temp_sum == 0)
    {
        is_a_plus_b_divisible_by_3 = true;
    }

    if (is_a_divisible_by_3 || is_b_divisible_by_3 || is_a_plus_b_divisible_by_3)
    {
        result = true;
    }
    return result;
}
