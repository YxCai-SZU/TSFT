/*@
    predicate valid_range(integer x) = 3 <= x && x <= 20;

    logic integer func_spec(integer a, integer b) =
        a == b ? a + b :
        a > b  ? 2 * a - 1 :
                 2 * b - 1;

    lemma func_non_negative:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> func_spec(a, b) >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0;
    ensures \result == func_spec(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    if (a == b)
    {
        //@ assert a + b >= 0;
        result = a + b;
    }
    else if (a > b)
    {
        //@ assert 2 * a - 1 >= 0;
        result = 2 * a - 1;
    }
    else
    {
        //@ assert 2 * b - 1 >= 0;
        result = 2 * b - 1;
    }

    return result;
}
