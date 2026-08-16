/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer func_spec(integer a, integer b, integer c) =
        (a - b >= c) ? 0 : (c - (a - b));
*/

/*@
    lemma func_lemma:
        \forall integer a, b, c;
        valid_params(a, b, c) ==>
        func_spec(a, b, c) >= 0 &&
        func_spec(a, b, c) <= c &&
        (a - b >= c ==> func_spec(a, b, c) == 0) &&
        (a - b < c ==> func_spec(a, b, c) == c - (a - b));
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (a - b >= c) ==> (\result == 0);
    ensures (a - b < c) ==> (\result == c - (a - b));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int ans;

    //@ assert valid_params(a, b, c);
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == (a < b ? a : b);
    
    if (a - min_val < c) {
        ans = c - (a - min_val);
    } else {
        ans = 0;
    }
    
    //@ assert ans == (a - min_val < c ? c - (a - min_val) : 0);
    
    //@ assert valid_params(a, b, c) ==> (a - b >= c ==> ans == 0);
    //@ assert valid_params(a, b, c) ==> (a - b < c ==> ans == c - (a - b));
    
    return ans;
}
