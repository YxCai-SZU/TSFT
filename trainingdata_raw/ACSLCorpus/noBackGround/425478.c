/*@
    requires (1 <= (a) && (a) <= 1000 &&
        1 <= (b) && (b) <= 1000 &&
        (a) + (b) <= (x) && (x) <= 10000);
    ensures \result >= 0 && \result <= x;
    ensures \result == ((x) - (a) - ((x) - (a) - (b) < 0 ? 0 : (x) - (a) - (b)));
*/
long func(long x, long a, long b)
{
    long remainder;
    long answer;

    remainder = x;
    remainder -= a;

    //@ assert remainder == x - a;

    if (remainder < 0)
    {
        //@ assert x - a < 0;
        //@ assert ((x) - (a) - ((x) - (a) - (b) < 0 ? 0 : (x) - (a) - (b))) == 0;
        return 0;
    }

    remainder -= b;

    //@ assert remainder == x - a - b;

    if (remainder < 0)
    {
        //@ assert x - a - b < 0;
        //@ assert ((x) - (a) - ((x) - (a) - (b) < 0 ? 0 : (x) - (a) - (b))) == x - a;
        return x - a;
    }

    answer = x - a;
    answer -= remainder;

    //@ assert answer == x - a - (x - a - b);
    //@ assert answer == ((x) - (a) - ((x) - (a) - (b) < 0 ? 0 : (x) - (a) - (b)));
    //@ assert answer >= 0;
    //@ assert answer <= x;

    return answer;
}
