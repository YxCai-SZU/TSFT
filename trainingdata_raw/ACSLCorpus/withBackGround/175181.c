#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer compute_sum(integer a, integer b, integer c) =
        a * 100 + b * 10 + c;

    lemma sum_mod_preserved:
        \forall integer sum, temp_sum;
        temp_sum >= 0 && temp_sum <= sum &&
        (temp_sum % 4) == (sum % 4) ==>
        temp_sum - 4 >= 0 ==>
        (temp_sum - 4) % 4 == sum % 4;
*/

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == (((a * 100 + b * 10 + c) % 4) < 1);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long sum;
    unsigned long long temp_sum;

    //@ assert in_range(a, b, c);
    sum = a * 100 + b * 10 + c;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop invariant in_range(a, b, c);
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 4)
    {
        //@ assert temp_sum % 4 == sum % 4;
        temp_sum -= 4;
        //@ assert temp_sum % 4 == sum % 4;
    }

    //@ assert temp_sum == sum % 4;
    //@ assert in_range(a, b, c);
    return temp_sum < 1;
}
