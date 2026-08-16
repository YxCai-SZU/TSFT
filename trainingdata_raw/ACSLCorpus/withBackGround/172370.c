/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer three_r_squared(integer r) = 3 * r * r;
    lemma bounds_lemma: \forall integer r; r_in_range(r) ==> 3 * r * r >= 3 && 3 * r * r <= 30000;
    lemma no_overflow_lemma: \forall integer r; r_in_range(r) ==> r * r <= 10000;
    lemma expression_equality_lemma: \forall integer r, integer rc; r_in_range(r) && rc == r * r * 3 ==> rc == three_r_squared(r);
*/

/*@
    requires r_in_range(r);
    ensures \result == three_r_squared(r);
    assigns \nothing;
*/
int func(int r)
{
    int r_cubed;

    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r >= 3;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r >= 3;
    //@ assert 3 * r * r <= 30000;
    //@ assert r * r <= 10000;
    //@ assert 3 * r * r <= 30000;

    r_cubed = r * r * 3;

    //@ assert r_cubed == 3 * r * r;

    return r_cubed;
}
