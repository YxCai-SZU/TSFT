/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 0 <= b <= a;

    logic integer half(integer a) = a / 2;

    logic integer expr1(integer a) = a - half(a);
    logic integer expr2(integer a) = a - half(a) + 1;

    predicate result_condition(integer a, integer b, integer r) =
        r == 1 <==> (b == expr1(a) || b == expr2(a));
*/

/*@
    requires is_valid_range(a, b);
    ensures result_condition(a, b, \result);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int half_a;
    int result;

    //@ assert is_valid_range(a, b);
    half_a = a / 2;
    result = 0;

    if (b == a - half_a || b == a - half_a + 1)
    {
        result = 1;
    }

    //@ assert result_condition(a, b, result);
    return result;
}
