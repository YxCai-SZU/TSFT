/*@
    predicate valid_range(integer l, integer r) =
        1 <= l && l <= r && r <= 100;

    predicate valid_divisor(integer d) =
        1 <= d && d <= 100;

    logic integer count_mod(integer l, integer r, integer d) =
        r - l + 1;

    lemma ans_bounds:
        \forall integer l, r, d, ans, i;
        valid_range(l, r) && valid_divisor(d) &&
        l <= i && i <= r + 1 && 0 <= ans && ans <= i - l ==>
        0 <= ans && ans <= count_mod(l, r, d);
*/

/*@
    requires valid_range(l, r) && valid_divisor(d);
    ensures 0 <= \result && \result <= r - l + 1;
*/
int func(long l, long r, long d)
{
    long ans = 0;
    long i = l;
    //@ assert l <= i && i <= r + 1;
    //@ assert ans >= 0 && ans <= i - l;
    
    /*@
        loop invariant l <= i && i <= r + 1;
        loop invariant 0 <= ans && ans <= i - l;
        loop assigns i, ans;
        loop variant r - i + 1;
    */
    while (i <= r) {
        long remainder = i;
        
        /*@
            loop invariant 0 <= remainder;
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= d) {
            remainder -= d;
        }
        
        //@ assert 0 <= remainder && remainder < d;
        if (remainder == 0) {
            ans += 1;
        }
        //@ assert ans >= 0 && ans <= i - l + 1;
        i += 1;
    }
    
    //@ assert 0 <= ans && ans <= r - l + 1;
    return ans;
}
