/*@
    predicate valid_input(integer a, integer b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;
    
    logic integer compute_result(integer a, integer b) =
        (a - 1) * (b - 1);
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int result;
    
    //@ assert a - 1 >= 1;
    //@ assert b - 1 >= 1;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    result = (a - 1) * (b - 1);
    return result;
}

int main()
{
    return 0;
}
