#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10;

    logic integer square(integer x) = x * x;
    logic integer cube(integer x) = x * x * x;
    logic integer target_formula(integer x) = cube(x) + 3 * square(x) + 2 * x;

    lemma square_bound: \forall integer x; is_valid_range(x) ==> square(x) <= 100;
    lemma cube_bound: \forall integer x; is_valid_range(x) ==> cube(x) <= 1000;
    lemma triple_square_bound: \forall integer x; is_valid_range(x) ==> 3 * square(x) <= 300;
    lemma double_x_bound: \forall integer x; is_valid_range(x) ==> 2 * x <= 20;
    lemma formula_bound: \forall integer x; is_valid_range(x) ==> target_formula(x) <= 1320;
*/

/*@
    requires is_valid_range(x);
    ensures \result == target_formula(x);
    assigns \nothing;
*/
int func(int x)
{
    // Declare all variables at the top
    int result;

    //@ assert is_valid_range(x);
    //@ assert square(x) <= 100;
    //@ assert cube(x) <= 1000;
    //@ assert 3 * square(x) <= 300;
    //@ assert 2 * x <= 20;
    //@ assert target_formula(x) <= 1320;

    result = x * x * x + 3 * x * x + 2 * x;

    //@ assert result == target_formula(x);
    return result;
}
