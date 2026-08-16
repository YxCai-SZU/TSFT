/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;
    predicate postcondition(integer x, integer result) =
        (x == 0 && result == 1) || (x == 1 && result == 0);
*/

/*@
    requires is_valid_input(x);
    ensures postcondition(x, \result);
*/
int func(int x)
{
    int result;
    //@ assert is_valid_input(x);
    if (x == 0) {
        //@ assert x == 0;
        result = 1;
    } else {
        //@ assert x == 1;
        result = 0;
    }
    //@ assert postcondition(x, result);
    return result;
}

/*@
    requires is_valid_input(x);
    ensures postcondition(x, \result);
*/
int func2(int x)
{
    int result;
    int y;
    //@ assert is_valid_input(x);
    if (x == 0) {
        y = 2 * x + 1;
        //@ assert x == 0;
        result = 1;
    } else {
        y = 2 * x + 1;
        //@ assert x == 1;
        result = 0;
    }
    //@ assert postcondition(x, result);
    return result;
}

/*@
    logic integer compute_y(integer x) = 2 * x + 1;
    lemma y_computation_zero: \forall integer x; x == 0 ==> compute_y(x) == 1;
    lemma y_computation_one: \forall integer x; x == 1 ==> compute_y(x) == 3;
*/

/*@
    requires is_valid_input(x);
    ensures postcondition(x, \result);
*/
int func3(int x)
{
    int result;
    int y;
    //@ assert is_valid_input(x);
    if (x == 0) {
        y = 2 * x + 1;
        //@ assert y == compute_y(x);
        //@ assert x == 0;
        //@ assert y == 1;
        result = 1;
    } else {
        y = 2 * x + 1;
        //@ assert y == compute_y(x);
        //@ assert x == 1;
        //@ assert y == 3;
        result = 0;
    }
    //@ assert postcondition(x, result);
    return result;
}
