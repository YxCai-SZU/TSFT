/*@
    requires ((a) >= -100 && (a) <= 100 &&
        (b) >= -100 && (b) <= 100 &&
        (c) >= -100 && (c) <= 100);
    ensures \result == a || \result == b || \result == c;
    ensures (((a) == (b) && (a) != (c)) ==> (\result) == (c));
    ensures (((a) == (c) && (a) != (b)) ==> (\result) == (b));
    ensures (((b) == (c) && (a) != (b)) ==> (\result) == (a));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result = 0;

    //@ assert a >= -100 && a <= 100;
    //@ assert b >= -100 && b <= 100;
    //@ assert c >= -100 && c <= 100;

    if (a == b && a != c)
    {
        result = c;
        //@ assert result == c;
    }
    else if (a == c && a != b)
    {
        result = b;
        //@ assert result == b;
    }
    else if (b == c && a != b)
    {
        result = a;
        //@ assert result == a;
    }
    else
    {
        result = a;
        //@ assert result == a;
    }

    //@ assert result == a || result == b || result == c;
    return result;
}
