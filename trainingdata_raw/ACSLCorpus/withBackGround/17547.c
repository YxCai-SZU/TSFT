/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_less_than_24(integer x) = x < 24;
    predicate is_less_than_48(integer x) = x < 48;
    predicate is_between_0_23(integer x) = 0 <= x && x <= 23;
    predicate is_between_1_100(integer x) = 1 <= x && x <= 100;
*/

/*@
    requires is_between_0_23(a) && is_between_1_100(b);
    ensures is_nonnegative(\result) && is_less_than_24(\result);
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    unsigned int result;

    sum = a + b;
    result = sum % 24;

    /*@
        loop invariant result >= -sum && result < 24;
        loop assigns result;
    */
    while (result < 0)
    {
        //@ assert result >= -sum;
        result += 24;
    }

    /*@
        loop invariant result >= 0 && result < 48;
        loop assigns result;
    */
    while (result >= 24)
    {
        //@ assert result < 48;
        result -= 24;
    }

    //@ assert result < 24;
    return result;
}
