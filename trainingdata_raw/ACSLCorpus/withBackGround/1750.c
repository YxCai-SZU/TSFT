/*@
    predicate is_valid_input(integer x, integer a) =
        0 <= x && x <= 9 &&
        0 <= a && a <= 9;

    predicate postcondition(integer x, integer a, integer result) =
        (x < a ==> result == 0) &&
        (x >= a ==> result == 10);
*/

/*@
    requires is_valid_input(x, a);
    ensures postcondition(x, a, \result);
*/
int func(int x, int a)
{
    int result;
    //@ assert is_valid_input(x, a);
    
    if (x < a)
    {
        //@ assert x < a;
        result = 0;
    }
    else
    {
        //@ assert x >= a;
        result = 10;
    }
    
    //@ assert postcondition(x, a, result);
    return result;
}
