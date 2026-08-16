/*@
    predicate bounds(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer func_result(integer a, integer b) =
        (a - 1) * (b - 1);
*/

/*@
    requires bounds(a, b);
    ensures \result == func_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int a_unfolded;
    int b_unfolded;
    int result;

    a_unfolded = a - 1;
    b_unfolded = b - 1;

    //@ assert 1 <= a_unfolded && a_unfolded <= 99;
    //@ assert 1 <= b_unfolded && b_unfolded <= 99;
    //@ assert 1 <= a_unfolded * b_unfolded && a_unfolded * b_unfolded <= 9801;

    result = a_unfolded * b_unfolded;
    return result;
}
