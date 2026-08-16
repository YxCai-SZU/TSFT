/*@
    predicate valid_range(integer v) = 3 <= v && v <= 20;
    
    logic integer sum(integer a, integer b) = a + b;
    
    lemma ans_bounds:
        \forall integer a, b, res, ans;
        valid_range(a) && valid_range(b) && 0 <= res && res <= sum(a,b) &&
        0 <= ans && ans <= (sum(a,b) - res)/2 ==>
        0 <= ans && ans <= sum(a,b);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0 && \result <= a + b;
*/
int func(int a, int b) {
    int res;
    int ans;
    
    res = a + b - 1;
    ans = 0;
    
    /*@
        loop invariant 3 <= a && a <= 20;
        loop invariant 3 <= b && b <= 20;
        loop invariant 0 <= res && res <= a + b;
        loop invariant 0 <= ans && ans <= (a + b - res)/2;
        loop assigns res, ans;
    */
    while (res >= 2) {
        //@ assert res >= 2;
        res -= 2;
        ans += 1;
    }
    
    //@ assert ans >= 0 && ans <= a + b;
    return ans;
}
