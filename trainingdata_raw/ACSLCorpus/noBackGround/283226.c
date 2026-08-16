/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 3 :
        ((a) == (b) || (b) == (c) || (a) == (c)) ? 2 : 1);
*/
int func(int a, int b, int c)
{
    int m;

    m = 0;

    if (a == b && b == c)
    {
        m = 3;
    }
    else if (a == b || b == c || a == c)
    {
        m = 2;
    }
    else
    {
        m = 1;
    }

    //@ assert m >= 1;
    //@ assert m <= 3;
    //@ assert m == (((a) == (b) && (b) == (c)) ? 3 :         ((a) == (b) || (b) == (c) || (a) == (c)) ? 2 : 1);

    return m;
}
