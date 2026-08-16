/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;

    logic integer func_result(integer a, integer b) =
        a - 2 * b > 0 ? a - 2 * b : 0;

    lemma result_non_negative:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> func_result(a, b) >= 0;

    lemma result_correct:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
                func_result(a, b) == a - 2 * b || func_result(a, b) == 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    int temp;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;

    temp = a - 2 * b;

    if (temp > 0)
    {
        //@ assert temp >= 0;
        result = temp;
    }
    else
    {
        //@ assert 0 >= 0;
        //@ assert temp <= 0;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == a - 2 * b || result == 0;
    return result;
}

int main()
{
    return 0;
}
