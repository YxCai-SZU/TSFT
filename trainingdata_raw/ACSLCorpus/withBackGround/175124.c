/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;

    logic integer perimeter_circle(integer r, integer pi) = r * 2 * pi;
    logic integer area_circle(integer r, integer pi) = r * r * pi;

    lemma perimeter_test: \forall integer r, pi; is_valid_range(r) ==> perimeter_circle(r, pi) == r * 2 * pi;
    lemma area_test: \forall integer r, pi; is_valid_range(r) ==> area_circle(r, pi) == r * r * pi;
*/

/*@
    requires is_valid_range(r);
    ensures \result == r * 2 * 3;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int result;

    pi = 3;
    //@ assert pi == 3;
    result = r * 2 * pi;
    //@ assert result == r * 2 * 3;
    return result;
}
