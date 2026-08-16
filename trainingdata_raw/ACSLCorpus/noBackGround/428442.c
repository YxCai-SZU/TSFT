/*@
    requires (1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20);
    ensures (((a) + (b)) <= 9 ==> \result == ((a) + (b))) &&
            (((a) + (b)) > 9 ==> \result == -1);
    assigns \nothing;
*/
long func(long a, long b)
{
    long result;

    //@ assert (1 <= (a) && (a) <= 20 &&         1 <= (b) && (b) <= 20);
    //@ assert 2 <= a + b && a + b <= 40;

    if (a + b <= 9)
    {
        //@ assert a + b <= 9;
        result = a + b;
    }
    else
    {
        //@ assert a + b > 9;
        result = -1;
    }

    return result;
}
