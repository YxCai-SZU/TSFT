/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer diff(integer x, integer y) = x - y;
    
    lemma diff_property:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        (diff(b, a) == diff(c, b)) == (b - a == c - b);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == (b - a == c - b);
*/
int func(int a, int b, int c) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    result = (b - a == c - b);
    
    return result;
}
