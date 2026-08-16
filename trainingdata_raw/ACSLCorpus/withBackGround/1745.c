/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 200;
    predicate condition_holds(integer a, integer b, integer x) = a <= x && x <= a + b;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (a <= x && x <= a + b);
    assigns \nothing;
*/
_Bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at the top
    _Bool result;

    // Proof logic translated to ACSL assertions
    //@ assert a_in_range(a);
    
    if (a <= x && x <= a + b) {
        //@ assert condition_holds(a, b, x);
        result = 1;
    } else {
        //@ assert !condition_holds(a, b, x);
        result = 0;
    }
    
    return result;
}
