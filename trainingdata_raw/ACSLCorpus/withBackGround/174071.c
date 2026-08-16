/*@
    predicate is_valid_input(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_sum(integer a, integer b) = a * 100 + b;

    lemma sum_bound: \forall integer a, b;
        is_valid_input(a, b) ==> compute_sum(a, b) <= 10100;
*/

#include <stdbool.h>

/*@
    requires is_valid_input(a, b);
    ensures \result == (compute_sum(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int sum;
    bool is_even;
    unsigned int temp_sum;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    //@ assert a * 100 <= 10000;
    //@ assert a * 100 + b <= 10100;
    
    sum = a * 100 + b;
    is_even = false;
    temp_sum = sum;
    
    /*@
        loop invariant 0 <= temp_sum && temp_sum <= compute_sum(a, b);
        loop invariant temp_sum <= sum;
        loop invariant sum == compute_sum(a, b);
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp_sum % 2 == sum % 2;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
    }
    
    if (temp_sum == 0)
    {
        is_even = true;
    }
    
    return is_even;
}
