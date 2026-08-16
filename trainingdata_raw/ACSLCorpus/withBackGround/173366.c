/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    logic integer is_greater(integer a, integer b) = a > b ? 1 : 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == is_greater(a, b);
    assigns \nothing;
*/
_Bool func(int a, int b) {
    _Bool result;

    //@ assert a_in_range(a) && b_in_range(b);
    
    if (a > b) {
        result = 1;
        //@ assert is_greater(a, b) == 1;
    } else {
        //@ assert a <= b;
        result = 0;
        //@ assert is_greater(a, b) == 0;
    }
    
    return result;
}
