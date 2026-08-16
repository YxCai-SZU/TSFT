/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;
    
    lemma max_is_either:
        \forall integer a, b, m;
            m == max_of_two(a, b) ==> (m == a || m == b);
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int max1;
    unsigned int max2;
    unsigned int ans;
    
    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    
    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }
    
    if (c > d) {
        max2 = c;
    } else {
        max2 = d;
    }
    
    //@ assert max1 == a || max1 == b;
    //@ assert max2 == c || max2 == d;
    
    //@ assert max1 <= 10000 && max2 <= 10000;
    //@ assert max1 + max2 <= 4294967295;
    
    ans = max1 + max2;
    
    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    
    return ans;
}
