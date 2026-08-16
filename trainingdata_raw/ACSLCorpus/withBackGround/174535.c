/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;
    
    predicate k_valid(integer k, integer a, integer b, integer c) =
        1 <= k && k <= a + b + c && a + b + c <= 2000000000;
    
    logic integer compute_a_cnt(integer a, integer k) =
        a < k ? a : k;
    
    logic integer compute_b_cnt(integer k, integer a_cnt) =
        k - a_cnt > 0 ? k - a_cnt : 0;
    
    logic integer compute_c_cnt(integer k, integer a_cnt, integer b_cnt) =
        k - a_cnt - b_cnt > 0 ? k - a_cnt - b_cnt : 0;
    
    lemma ans_bounds:
        \forall integer a, b, c, k, a_cnt, b_cnt, c_cnt, ans;
        non_negative(a, b, c) && k_valid(k, a, b, c) &&
        a_cnt == compute_a_cnt(a, k) &&
        b_cnt == compute_b_cnt(k, a_cnt) &&
        c_cnt == compute_c_cnt(k, a_cnt, b_cnt) &&
        ans == a_cnt - c_cnt ==>
        ans <= a && ans >= 0;
*/

/*@
    requires non_negative(a, b, c) && k_valid(k, a, b, c);
    ensures \result <= a && \result >= 0;
*/
int func(int a, int b, int c, int k)
{
    int a_cnt;
    int b_cnt;
    int c_cnt;
    int ans;
    int ans_abs;
    
    //@ assert non_negative(a, b, c);
    //@ assert k_valid(k, a, b, c);
    
    a_cnt = a < k ? a : k;
    //@ assert a_cnt == compute_a_cnt(a, k);
    
    b_cnt = k - a_cnt > 0 ? k - a_cnt : 0;
    //@ assert b_cnt == compute_b_cnt(k, a_cnt);
    
    c_cnt = k - a_cnt - b_cnt > 0 ? k - a_cnt - b_cnt : 0;
    //@ assert c_cnt == compute_c_cnt(k, a_cnt, b_cnt);
    
    ans = a_cnt - c_cnt;
    //@ assert ans == a_cnt - c_cnt;
    
    ans_abs = ans < 0 ? -ans : ans;
    //@ assert ans_abs >= 0;
    
    //@ assert ans <= a;
    //@ assert ans >= 0;
    
    return ans;
}
