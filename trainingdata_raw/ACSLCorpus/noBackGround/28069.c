/*@
    requires (1 <= (N) && (N) <= 100000);
    ensures ((\result) == 0 || (\result) == 1);
    ensures ((\result) == 1 ==> ((N) % 100) * 21 + 1 == (N));
    ensures ((\result) == 0 ==> ((N) % 100) * 21 + 1 != (N));
*/
int func(int N)
{
    int result;
    int i;
    result = 0;
    i = 1;
    /*@
        loop invariant 1 <= i && i <= 100;
        loop invariant ((result) == 0 || (result) == 1);
        loop invariant ((result) == 1 ==> ((N) % 100) * 21 + 1 == (N));
        loop invariant ((result) == 0 ==> ((N) % 100) * 21 + 1 != (N));
        loop assigns i, result;
        loop variant 100 - i;
    */
    while (i < 100)
    {
        int x;
        x = N - i * 100;
        if (x > 0)
        {
            //@ assert x == N - i * 100;
            if (x * 21 + 1 == N)
            {
                result = 1;
                break;
            }
        }
        i = i + 1;
    }
    return result;
}
