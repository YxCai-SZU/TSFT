/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer func_result(integer a, integer b, integer c) =
        (c < (a - b)) ? (c - c) : (c - (a - b));

    lemma result_properties:
        \forall integer a, b, c;
        valid_params(a, b, c) ==>
        (
            func_result(a, b, c) >= 0 &&
            func_result(a, b, c) <= c &&
            (func_result(a, b, c) == c - (a - b) || func_result(a, b, c) == 0)
        );
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int ans;
    int result;

    //@ assert valid_params(a, b, c);

    if (c < (a - b))
    {
        min_val = c;
    }
    else
    {
        min_val = a - b;
    }

    ans = c - min_val;

    if (ans > 0)
    {
        //@ assert ans >= 0;
        result = ans;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}
