/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer expression(integer x) = x * x;

    lemma expression_square: \forall integer x; expression(x) == x * x;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int result = 0;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    if (b >= a && c >= a)
    {
        result += a;
        //@ assert result == a;
    }
    else if (b >= c && a >= c)
    {
        result += c;
        //@ assert result == c;
    }
    else
    {
        result += b;
        //@ assert result == b;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c;
    return result;
}
