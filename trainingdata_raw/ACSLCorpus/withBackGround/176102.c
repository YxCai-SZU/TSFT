/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    logic integer double_b(integer b) = b * 2;
    logic integer func_spec(integer a, integer b) = 
        a > double_b(b) ? a - double_b(b) : 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == func_spec(a, b);
    ensures \result >= 0;
*/
unsigned int func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert double_b(b) <= 200;
    //@ assert a >= double_b(b) || a < double_b(b);
    
    if (a > b * 2) {
        result = a - b * 2;
    } else {
        result = 0;
    }
    
    //@ assert result == func_spec(a, b);
    //@ assert result >= 0;
    
    return result;
}
