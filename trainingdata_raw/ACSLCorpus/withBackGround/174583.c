/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 10;
    logic integer compute_formula(integer x) = x * x * x + 3 * x * x + 2 * x + 1;
    lemma bounds_lemma: \forall integer x; is_valid_range(x) ==> x * x <= 100;
    lemma cube_bounds_lemma: \forall integer x; is_valid_range(x) ==> x * x * x <= 1000;
    lemma triple_square_bounds_lemma: \forall integer x; is_valid_range(x) ==> 3 * x * x <= 300;
    lemma double_bounds_lemma: \forall integer x; is_valid_range(x) ==> 2 * x <= 20;
*/

/*@
    requires is_valid_range(x);
    ensures \result == compute_formula(x);
    assigns \nothing;
*/
int func(int x)
{
    int x_cubed;
    int three_x_squared;
    int two_x;
    int result;

    //@ assert 1 <= x && x <= 10;
    //@ assert x * x <= 100;
    //@ assert x * x * x <= 1000;
    //@ assert 3 * x * x <= 300;
    //@ assert 2 * x <= 20;

    x_cubed = x * x * x;
    three_x_squared = 3 * x * x;
    two_x = 2 * x;
    result = x_cubed + three_x_squared + two_x + 1;

    return result;
}
