/*@
    requires (-1000 <= (a) <= (b) <= 1000 &&
        -1000 <= (c) <= (d) <= 1000 &&
        (a) * (c) <= 1000000000 &&
        (a) * (d) <= 1000000000 &&
        (b) * (c) <= 1000000000 &&
        (b) * (d) <= 1000000000);
    ensures \result == ((a) * (c)) ||
            \result == ((a) * (d)) ||
            \result == ((b) * (c)) ||
            \result == ((b) * (d));
    ensures \result >= ((a) * (c));
    ensures \result >= ((a) * (d));
    ensures \result >= ((b) * (c));
    ensures \result >= ((b) * (d));
*/
int func(int a, int b, int c, int d)
{
    int ac;
    int ad;
    int bc;
    int bd;
    int max_val;

    //@ assert -1000000000 <= a * c <= 1000000000;
    ac = a * c;

    //@ assert -1000000000 <= a * d <= 1000000000;
    ad = a * d;

    //@ assert -1000000000 <= b * c <= 1000000000;
    bc = b * c;

    //@ assert -1000000000 <= b * d <= 1000000000;
    bd = b * d;

    max_val = ac;

    if (ad > max_val)
    {
        max_val = ad;
    }

    if (bc > max_val)
    {
        max_val = bc;
    }

    if (bd > max_val)
    {
        max_val = bd;
    }

    return max_val;
}
