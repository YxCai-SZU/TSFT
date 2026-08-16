/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
    
    logic integer sum(integer x, integer y) = x + y;
    
    lemma sum_bounds:
        \forall integer a, b;
        is_valid_range(a) && is_valid_range(b) ==> 1 <= sum(a, b) <= 202;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && 
             is_valid_range(c) && is_valid_range(d);
    ensures \result == a + b || \result == c + d;
    ensures 1 <= \result <= 202;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int min_ab;
    int min_cd;
    
    //@ assert is_valid_range(a) && is_valid_range(b);
    //@ assert is_valid_range(c) && is_valid_range(d);
    
    if (a + b < c + d) {
        min_ab = a + b;
    } else {
        min_ab = c + d;
    }
    
    if (c + d < a + b) {
        min_cd = c + d;
    } else {
        min_cd = a + b;
    }
    
    //@ assert min_ab == a + b || min_ab == c + d;
    //@ assert 1 <= min_ab <= 202;
    
    return min_ab;
}
