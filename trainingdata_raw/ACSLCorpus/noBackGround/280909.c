/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == a + c || \result == b + c;
    assigns \nothing;
*/
long func(long a, long b, long c)
{
    long result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert a + b >= 2 && a + b <= 200;
    //@ assert a + c >= 2 && a + c <= 200;
    //@ assert b + c >= 2 && b + c <= 200;

    if (a + b < a + c)
    {
        if (a + b < b + c)
        {
            result = a + b;
            //@ assert result == ((a) + (b));
        }
        else
        {
            result = b + c;
            //@ assert result == ((b) + (c));
        }
    }
    else if (a + c < b + c)
    {
        result = a + c;
        //@ assert result == ((a) + (c));
    }
    else
    {
        result = b + c;
        //@ assert result == ((b) + (c));
    }

    //@ assert result == a + b || result == a + c || result == b + c;
    return result;
}
