/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == 1 <==> (((a) == 5 && ((b) == 5 || (c) == 5)) || ((b) == 5 && ((c) == 5 || (a) == 5)));
 */
int func(int a, int b, int c)
{
    int cnt = 0;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    if (a == 5)
    {
        cnt += 1;
    }
    if (b == 5)
    {
        cnt += 1;
    }
    if (c == 5)
    {
        cnt += 1;
    }

    //@ assert cnt >= 2 ==> (((a) == 5 && ((b) == 5 || (c) == 5)) || ((b) == 5 && ((c) == 5 || (a) == 5)));

    return cnt >= 2;
}
