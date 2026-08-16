/*@
    predicate is_valid_input(integer X) =
        0 <= X && X <= 1;

    logic integer func_spec(integer X) =
        1 - X;

    lemma func_result_range:
        \forall integer X;
        is_valid_input(X) ==>
        (func_spec(X) == 0 || func_spec(X) == 1);
*/

/*@
    requires is_valid_input(X);
    ensures \result == func_spec(X);
    ensures \result == 0 || \result == 1;
*/
int func(int X)
{
    int result;

    //@ assert is_valid_input(X);
    result = 1 - X;
    //@ assert result == 1 - X;
    //@ assert result == 0 || result == 1;

    return result;
}
