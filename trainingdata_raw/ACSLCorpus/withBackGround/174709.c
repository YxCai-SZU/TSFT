/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer compute_ans(integer a, integer b) = a - (b * 2);
    
    lemma ans_identity: \forall integer a, b, ans;
        valid_range(a, b) && ans == compute_ans(a, b) ==> ans == a - (b * 2);
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - (b * 2) || \result == 0;
*/
int func(int a, int b)
{
    int ans;
    int res;
    
    ans = a - (b * 2);
    
    //@ assert valid_range(a, b);
    //@ assert ans == compute_ans(a, b);
    //@ assert ans == a - (b * 2);
    
    if (ans > 0)
    {
        //@ assert ans > 0;
        res = ans;
    }
    else
    {
        //@ assert ans <= 0;
        res = 0;
    }
    
    //@ assert res >= 0;
    //@ assert res == a - (b * 2) || res == 0;
    
    return res;
}
