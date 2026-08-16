/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int sa = a;
    int sb = b;
    int sc = c;
    int sd = d;
    int temp;
    int s;

    //@ assert (1 <= (sa) <= 10000) && (1 <= (sb) <= 10000) && (1 <= (sc) <= 10000) && (1 <= (sd) <= 10000);

    if (sa > sb)
    {
        temp = sa;
        sa = sb;
        sb = temp;
    }
    //@ assert sa <= sb;

    if (sc > sd)
    {
        temp = sc;
        sc = sd;
        sd = temp;
    }
    //@ assert sc <= sd;

    //@ assert (1 <= (sa) <= 10000) && (1 <= (sb) <= 10000) && (1 <= (sc) <= 10000) && (1 <= (sd) <= 10000);
    //@ assert 1 <= sa * sb <= 10000 * 10000;
    //@ assert 1 <= sc * sd <= 10000 * 10000;

    if (sa * sb > sc * sd)
    {
        s = sa * sb;
        //@ assert s == a * b || s == c * d;
    }
    else
    {
        s = sc * sd;
        //@ assert s == a * b || s == c * d;
    }

    //@ assert s >= 1;
    return s;
}
