/*@
    requires a > -0x80000000 && a < 0x80000000;
    requires b > -0x80000000 && b < 0x80000000;
    requires c > -0x80000000 && c < 0x80000000;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
*/
int func(int a, int b, int c)
{
    int i;
    int j;
    int k;
    int temp;

    i = a;
    j = b;
    k = c;

    if (i > j)
    {
        temp = i;
        i = j;
        j = temp;
    }

    if (j > k)
    {
        temp = j;
        j = k;
        k = temp;
    }

    if (i > j)
    {
        temp = i;
        i = j;
        j = temp;
    }

    //@ assert ((i) <= (j) && (j) <= (k));

    return (i < b && b < c);
}
