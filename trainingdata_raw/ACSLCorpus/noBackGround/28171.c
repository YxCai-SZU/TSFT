/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    requires a != b && a != c && b != c;
    ensures \result == 1 <==> (((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)));
 */
int func(int a, int b, int c)
{
    int min;
    int max;
    int c_in_range;

    if (a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }

    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    c_in_range = (min < c && c < max);

    //@ assert c_in_range == 1 <==> (((a) < (c) && (c) < (b)) || ((b) < (c) && (c) < (a)));

    return c_in_range;
}
