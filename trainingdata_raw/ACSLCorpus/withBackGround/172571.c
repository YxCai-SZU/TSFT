/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    predicate no_overflow(integer r) = 3 * r * r <= 300 * 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == 3 * r * r;
    ensures no_overflow(r);
*/
int func(int r)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r >= 0;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;

    result = 3 * r * r;
    return result;
}
