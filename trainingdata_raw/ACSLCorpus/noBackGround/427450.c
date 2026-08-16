/*@
    requires ((a) >= 1 && (a) <= 9 &&
        (b) >= 1 && (b) <= 9 &&
        (c) >= 1 && (c) <= 9);
    ensures \result == (((b) - (a)) == ((c) - (b)));
    assigns \nothing;
*/
int func(long long a, long long b, long long c)
{
    long long diff1;
    long long diff2;
    int result;

    //@ assert ((a) >= 1 && (a) <= 9 &&         (b) >= 1 && (b) <= 9 &&         (c) >= 1 && (c) <= 9);
    //@ assert ((b) - (a)) >= -8 && ((b) - (a)) <= 8;
    diff1 = b - a;
    //@ assert ((c) - (b)) >= -8 && ((c) - (b)) <= 8;
    diff2 = c - b;
    //@ assert diff1 == ((b) - (a));
    //@ assert diff2 == ((c) - (b));
    result = (diff1 == diff2);
    //@ assert result == (((b) - (a)) == ((c) - (b)));
    return result;
}
