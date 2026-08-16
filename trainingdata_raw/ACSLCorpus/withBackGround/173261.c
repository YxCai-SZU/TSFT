/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate(integer r, integer g, integer b) = r * 100 + g * 10 + b;

    lemma r_bound: \forall integer r; valid_range(r) ==> 100 <= r * 100 <= 900;
    lemma g_bound: \forall integer g; valid_range(g) ==> 10 <= g * 10 <= 90;
    lemma b_bound: \forall integer b; valid_range(b) ==> 1 <= b <= 9;
    lemma ans_bound: \forall integer r, integer g, integer b;
        valid_range(r) && valid_range(g) && valid_range(b) ==> 111 <= calculate(r, g, b) <= 999;
*/

/*@
    requires 1 <= r <= 9;
    requires 1 <= g <= 9;
    requires 1 <= b <= 9;
    ensures \result == r * 100 + g * 10 + b;
*/
int func(int r, int g, int b)
{
    int ans;

    //@ assert valid_range(r);
    //@ assert valid_range(g);
    //@ assert valid_range(b);
    
    ans = r * 100 + g * 10 + b;
    
    //@ assert 100 <= r * 100 <= 900;
    //@ assert 10 <= g * 10 <= 90;
    //@ assert 1 <= b <= 9;
    //@ assert 111 <= ans <= 999;
    
    return ans;
}
