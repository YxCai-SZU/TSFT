/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == 1 <==> ((a) > (b) && (b) > (c) && (c) > (d));
    ensures \result == 0 <==> !((a) > (b) && (b) > (c) && (c) > (d));
*/
int func(int a, int b, int c, int d)
{
    int greater;

    greater = 0;

    if (a > b)
    {
        greater = 1;
    }

    if (greater && b > c)
    {
        greater = 1;
    }
    else
    {
        greater = 0;
    }

    if (greater && c > d)
    {
        greater = 1;
    }
    else
    {
        greater = 0;
    }

    //@ assert greater == 1 <==> ((a) > (b) && (b) > (c) && (c) > (d));

    return greater;
}
