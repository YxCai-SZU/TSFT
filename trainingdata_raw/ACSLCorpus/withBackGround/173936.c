#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer x, integer y) = x + y;

    lemma sum_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            2 <= sum(a, b) <= 200;

    lemma max_property:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            (sum(a, b) == sum(b, c) || sum(b, c) == sum(c, a) || sum(c, a) == sum(a, b) ||
             sum(a, b) >= sum(b, c) && sum(a, b) >= sum(c, a) ||
             sum(b, c) >= sum(a, b) && sum(b, c) >= sum(c, a) ||
             sum(c, a) >= sum(a, b) && sum(c, a) >= sum(b, c));
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == a + b || \result == b + c || \result == c + a;
    ensures 2 <= \result <= 200;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int abc[3];
    int max_value;
    int i;

    abc[0] = a + b;
    abc[1] = b + c;
    abc[2] = c + a;

    max_value = abc[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \exists integer k; 0 <= k < i && max_value == abc[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= abc[j];
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant abc[0] == a + b;
        loop invariant abc[1] == b + c;
        loop invariant abc[2] == c + a;
        loop invariant 2 <= max_value <= 200;
        loop invariant 2 <= a + b <= 200;
        loop invariant 2 <= b + c <= 200;
        loop invariant 2 <= c + a <= 200;
        loop assigns i, max_value;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (abc[i] > max_value)
        {
            max_value = abc[i];
        }
        i = i + 1;
    }

    //@ assert max_value == a + b || max_value == b + c || max_value == c + a;
    return max_value;
}
