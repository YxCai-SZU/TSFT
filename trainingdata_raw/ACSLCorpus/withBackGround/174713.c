#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer fixed_representation(integer v) = v * 100;
    logic integer truncated(integer v) = v / 100;

    lemma truncation_identity: \forall integer v; valid_range(v) ==> truncated(fixed_representation(v)) == v;
    lemma fixed_bound: \forall integer v; valid_range(v) ==> fixed_representation(v) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (truncated(fixed_representation(a)) == truncated(fixed_representation(b)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int x;
    unsigned int y;
    unsigned int x_fixed;
    unsigned int y_fixed;
    bool result;

    //@ assert fixed_representation(a) <= 10000;
    //@ assert fixed_representation(b) <= 10000;
    
    x = a * 100;
    y = b * 100;
    
    x_fixed = x / 100;
    y_fixed = y / 100;
    
    //@ assert x_fixed == a;
    //@ assert y_fixed == b;
    
    result = (x_fixed == y_fixed);
    return result;
}
