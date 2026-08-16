/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    logic integer expected_result(integer r) = 6 * r;
    logic integer max_bound(integer r) = 2 * 100 * 3;
    lemma bound_lemma: \forall integer r; r_in_range(r) ==> 2 * r * 3 <= max_bound(r);
*/

/*@
    requires r_in_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
long func(long r)
{
    long pi;
    long result;

    // Variable declarations at top
    pi = 3;
    result = 0;

    //@ assert 2 * r * pi <= 2 * 100 * 3;
    result = 2 * r * pi;
    return result;
}
