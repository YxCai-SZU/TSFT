#include <stddef.h>
#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;
    logic integer total_sum(integer a, integer b, integer c) = a + b + c;

    predicate element_exists(int *arr, integer len, integer idx, integer val) =
        0 <= idx < len && arr[idx] == val;

    predicate is_min_up_to(int *arr, integer len, integer i, integer min_val) =
        \exists integer j; 0 <= j < i && element_exists(arr, len, j, min_val) &&
        \forall integer k; 0 <= k < i ==> min_val <= arr[k];

    lemma vs_properties:
        \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        sum_ab(a, b) <= total_sum(a, b, c) &&
        sum_bc(b, c) <= total_sum(a, b, c) &&
        sum_ca(c, a) <= total_sum(a, b, c);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == c + a;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int vs[3];
    unsigned int min_val;
    unsigned int i;

    vs[0] = a + b;
    vs[1] = b + c;
    vs[2] = c + a;

    min_val = vs[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \exists integer j; 0 <= j < i && vs[j] == min_val;
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= vs[k];
        loop invariant vs[0] == a + b;
        loop invariant vs[1] == b + c;
        loop invariant vs[2] == c + a;
        loop invariant min_val <= a + b + c;
        loop assigns i, min_val;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (vs[i] < min_val)
        {
            min_val = vs[i];
        }
        i++;
    }

    //@ assert min_val == vs[0] || min_val == vs[1] || min_val == vs[2];
    return min_val;
}
