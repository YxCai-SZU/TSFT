/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 3;

    lemma subtraction_bounds:
        \forall integer a, b;
            is_valid_range(a) && is_valid_range(b) && a != b ==>
                1 <= 6 - a - b && 6 - a - b <= 3;
*/

/*@
    requires a != b;
    requires 1 <= a && a <= 3;
    requires 1 <= b && b <= 3;
    ensures \result >= 1 && \result <= 3;
    ensures \result != a;
    ensures \result != b;
*/
long func(long a, long b) {
    // Variable declarations at scope top
    long ans;

    //@ assert 6 - a >= 1;
    //@ assert 6 - a - b >= 1;
    //@ assert 6 - a <= 5;
    //@ assert 6 - a - b <= 5;

    ans = 6 - a - b;
    return ans;
}
