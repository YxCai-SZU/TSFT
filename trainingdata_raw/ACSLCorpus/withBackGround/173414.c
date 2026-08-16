/*@
    predicate is_valid_input(integer a, integer b) =
        1 <= a && a <= 12 &&
        1 <= b && b <= 31;

    predicate result_one_condition(integer a, integer b) =
        (a <= 9 && b >= 13) || (a > 9 && b >= 1);

    predicate result_zero_condition(integer a, integer b) =
        (a <= 9 && b < 13) || (a > 9 && b < 1);

    lemma result_implication:
        \forall integer a, b;
            is_valid_input(a, b) && !result_one_condition(a, b) ==>
            result_zero_condition(a, b);
*/

/*@
    requires is_valid_input(a, b);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> result_one_condition(a, b);
    ensures \result == 0 ==> result_zero_condition(a, b);
*/
int func(unsigned int a, unsigned int b)
{
    int result;

    //@ assert is_valid_input(a, b);
    if ((a <= 9 && b >= 13) || (a > 9 && b >= 1)) {
        result = 1;
        //@ assert result_one_condition(a, b);
    } else {
        //@ assert !result_one_condition(a, b);
        //@ assert result_zero_condition(a, b);
        result = 0;
    }

    return result;
}
