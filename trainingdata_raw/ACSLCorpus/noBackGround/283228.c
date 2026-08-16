/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures ((\result) == (((a) == (b) && (a) != (c)) || ((a) == (c) && (a) != (b)) || ((b) == (c) && (a) != (b))));
*/
int func(int a, int b, int c)
{
    int state = 0;

    //@ assert state == 0;

    if (a == b)
    {
        state = 1;
    }

    if (a == c)
    {
        state = state + 2;
    }

    if (b == c)
    {
        state = state + 4;
    }

    //@ assert state == 0 || state == 1 || state == 2 || state == 4 || state == 5 || state == 6 || state == 7;

    return (state == 1 || state == 2 || state == 4) ? 1 : 0;
}
