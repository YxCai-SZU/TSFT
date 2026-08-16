/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) && (b) != (c)) ||
        ((b) == (c) && (c) != (a)) ||
        ((c) == (a) && (a) != (b)));
    ensures \result == 0 <==> !(((a) == (b) && (b) != (c)) ||
        ((b) == (c) && (c) != (a)) ||
        ((c) == (a) && (a) != (b)));
 */
int func(int a, int b, int c)
{
    int result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if ((a == b) && (b == c))
    {
        result = 0;
        //@ assert !(((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    }
    else if ((a == b) || (b == c) || (c == a))
    {
        //@ assert (a == b) || (b == c) || (c == a);
        //@ assert !((a == b) && (b == c));
        result = 1;
        //@ assert (((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    }
    else
    {
        result = 0;
        //@ assert !(((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    }

    return result;
}
