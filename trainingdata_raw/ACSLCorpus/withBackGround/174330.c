#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10;

    logic integer result_expr(integer a) = a * (1 + a + a * a);

    lemma a_plus_a_bound: \forall integer a; valid_range(a) ==> a + a <= 2 * a;
    lemma a_cubed_bound: \forall integer a; valid_range(a) ==> a * a * a <= a * a * 10;
    lemma quadratic_plus_bound: \forall integer a; valid_range(a) ==> a * a + a + 1 <= a * a + 10 + 1;
    lemma a_squared_bound: \forall integer a; valid_range(a) ==> a * a <= 100;
    lemma a_times_linear_bound: \forall integer a; valid_range(a) ==> a * (1 + a) <= a * 11;
    lemma full_expr_bound: \forall integer a; valid_range(a) ==> a * (1 + a + a * a) <= a * 112;
    lemma final_bound: \forall integer a; valid_range(a) ==> a * (1 + a + a * a) <= 10 * 112;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == a * (1 + a + a * a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Declare all variables at the top
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert a + a <= 2 * a;
    //@ assert a * a * a <= a * a * 10;
    //@ assert a * a + a + 1 <= a * a + 10 + 1;
    //@ assert a * a <= 100;
    //@ assert a * (1 + a) <= a * 11;
    //@ assert a * (1 + a + a * a) <= a * 112;
    //@ assert a * (1 + a + a * a) <= 10 * 112;

    result = a * (1 + a + a * a);
    
    //@ assert result == result_expr(a);
    return result;
}
