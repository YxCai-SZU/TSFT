/*@
    predicate is_in_range(integer a) = 1 <= a && a <= 10;
    predicate result_condition(integer a, integer result) = result == (a > 5);
*/

/*@
    requires is_in_range(a);
    ensures result_condition(a, \result);
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= a && a <= 10;
    
    result = a > 5;
    return result;
}
