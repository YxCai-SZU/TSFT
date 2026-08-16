/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer func_spec(integer a, integer b, integer c, integer d) =
        (c * 2 <= a + b) ? ((a + b + c + d) / 2) : (b + d + c);

    lemma func_verification:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            func_spec(a, b, c, d) == ((c * 2 <= a + b) ? ((a + b + c + d) / 2) : (b + d + c));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == func_spec(a, b, c, d);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int result = 0;

    if (c * 2 <= a + b)
    {
        result = a + b + c + d;
        result = result / 2;
        //@ assert result == (a + b + c + d) / 2;
    }
    else
    {
        result = b + d + c;
        //@ assert result == b + d + c;
    }

    return result;
}
