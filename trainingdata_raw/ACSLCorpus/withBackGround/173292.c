#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer compute_result(integer x) = x * (1 + x * (1 + x));

    lemma unsigned_bounds:
        \forall integer x; valid_range(x) ==> 1 <= (unsigned)x <= 10;

    lemma square_bounds:
        \forall integer x; valid_range(x) ==> 1 <= (unsigned)x * (unsigned)x <= 100;

    lemma cube_bounds:
        \forall integer x; valid_range(x) ==> 1 <= (unsigned)x * (unsigned)x * (unsigned)x <= 1000;

    lemma inner_expr_bounds:
        \forall integer x; valid_range(x) ==> 1 <= 1 + (unsigned)x * (1 + (unsigned)x) <= 111;

    lemma final_expr_bounds:
        \forall integer x; valid_range(x) ==> 1 <= (unsigned)x * (1 + (unsigned)x * (1 + (unsigned)x)) <= 1110;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int func(int x)
{
    unsigned int x_unsigned;
    unsigned int result;
    int signed_result;

    //@ assert valid_range(x);
    
    if (x < 0)
    {
        x_unsigned = (unsigned int)(-x);
    }
    else
    {
        x_unsigned = (unsigned int)x;
    }

    //@ assert 1 <= x_unsigned <= 10;
    //@ assert x_unsigned * x_unsigned >= 1 && x_unsigned * x_unsigned <= 100;
    //@ assert x_unsigned * x_unsigned * x_unsigned >= 1 && x_unsigned * x_unsigned * x_unsigned <= 1000;
    //@ assert 1 + x_unsigned * (1 + x_unsigned) >= 1 && 1 + x_unsigned * (1 + x_unsigned) <= 111;
    //@ assert x_unsigned * (1 + x_unsigned * (1 + x_unsigned)) >= 1 && x_unsigned * (1 + x_unsigned * (1 + x_unsigned)) <= 1110;

    result = x_unsigned * (1 + x_unsigned * (1 + x_unsigned));

    if (x < 0)
    {
        signed_result = -(int)result;
    }
    else
    {
        signed_result = (int)result;
    }

    //@ assert signed_result == compute_result(x);
    return signed_result;
}
