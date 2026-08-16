/*@
    predicate is_valid_range(integer x) = 0 <= x <= 5000;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures \result == (a < c && c < b && b < d);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    // Variable declarations at the top
    int result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    //@ assert is_valid_range(d);
    
    result = (a < c && c < b && b < d);
    return result;
}
