/*@
    predicate valid_range(integer v) =
        1 <= v <= 20;

    lemma loop_invariant_maintained:
        \forall integer i, m, result;
            0 <= i <= m &&
            result == i * 2 * 3 &&
            valid_range(m) ==>
            (i < m ==> result + 2 * 3 == (i + 1) * 2 * 3);
*/

/*@
    requires valid_range(n) && valid_range(m);
    ensures \result == m * 2 * 3;
*/
int func(int n, int m)
{
    int result = 0;
    int i = 0;
    
    //@ ghost int original_m = m;
    //@ ghost int original_n = n;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant result == i * 2 * 3;
        loop invariant valid_range(original_n);
        loop invariant valid_range(original_m);
        loop assigns i, result;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert result == i * 2 * 3;
        result += 2 * 3;
        i += 1;
        //@ assert result == i * 2 * 3;
    }
    
    //@ assert result == m * 2 * 3;
    return result;
}
