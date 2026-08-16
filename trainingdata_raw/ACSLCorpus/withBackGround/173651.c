#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer combine(integer b, integer c) = b * 10 + c;
    logic integer scaled_a(integer a) = a * 10;

    lemma combine_bounds: \forall integer b, c; valid_range(b) && valid_range(c) ==> 1 <= combine(b,c) <= 99;
    lemma scaled_a_bounds: \forall integer a; valid_range(a) ==> 10 <= scaled_a(a) <= 90;
    lemma diff_nonnegative_implication: \forall integer a,b,c; valid_range(a) && valid_range(b) && valid_range(c) ==> 
        (combine(b,c) - scaled_a(a) >= 0 ==> combine(b,c) - scaled_a(a) >= 0);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == ((b * 10 + c) - a * 10 >= 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Declare all variables at the top
    bool result;
    int combined;
    int scaled;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    //@ assert 1 <= b * 10 + c <= 99;
    //@ assert 10 <= a * 10 <= 90;
    //@ assert (b * 10 + c) - a * 10 >= 0 ==> (b * 10 + c) - a * 10 >= 0;

    combined = b * 10 + c;
    scaled = a * 10;
    result = (combined - scaled) >= 0;

    return result;
}
