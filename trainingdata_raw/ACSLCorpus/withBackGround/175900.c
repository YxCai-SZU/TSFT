#include <stdbool.h>

/*@
    predicate range(integer v) = 0 <= v <= 100;

    predicate in_range(integer a, integer b, integer x) =
        x <= a && a <= x + b;

    lemma range_implication:
        \forall integer a, b, x;
        range(a) && range(b) && range(x) && in_range(a, b, x) ==>
        in_range(a, b, x);
*/

/*@
    requires range(a) && range(b) && range(x);
    ensures \result == (x <= a && a <= x + b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long local_a = a;
    unsigned long long local_b = b;
    unsigned long long local_x = x;
    bool result;

    //@ assert range(local_a);
    
    //@ assert range(local_b);
    
    //@ assert range(local_x);

    //@ assert in_range(local_a, local_b, local_x) ==> in_range(local_a, local_b, local_x);

    result = (local_x <= local_a) && (local_a <= local_x + local_b);

    //@ assert result == (local_x <= local_a && local_a <= local_x + local_b);

    return result;
}
