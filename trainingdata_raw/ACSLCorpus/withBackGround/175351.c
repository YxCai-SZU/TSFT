/*@
    predicate is_valid_range(integer x) = 1 <= x <= 5000;
    
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma ans_properties:
        \forall integer a, b, c, d, train, bus, ans;
        is_valid_range(a) && is_valid_range(b) && 
        is_valid_range(c) && is_valid_range(d) &&
        train == min(a, b) && bus == min(c, d) && ans == train + bus ==>
        ans >= train && ans >= bus && ans <= a + b + c + d;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && 
             is_valid_range(c) && is_valid_range(d);
    ensures \result >= (a < b ? a : b);
    ensures \result >= (c < d ? c : d);
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int train;
    int bus;
    int ans;
    
    //@ assert is_valid_range(a) && is_valid_range(b);
    //@ assert is_valid_range(c) && is_valid_range(d);
    
    train = a < b ? a : b;
    bus = c < d ? c : d;
    
    //@ assert train == min(a, b);
    //@ assert bus == min(c, d);
    
    ans = train + bus;
    
    //@ assert ans >= train && ans >= bus;
    //@ assert ans <= a + b + c + d;
    
    return ans;
}
