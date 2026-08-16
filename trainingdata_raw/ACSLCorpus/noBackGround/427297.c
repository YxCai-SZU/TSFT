/*@
    requires (1 <= (x) && (x) <= 100);
    requires (1 <= (y) && (y) <= 100);
    assigns \nothing;
    ensures \result == (2 * x <= y);
*/
_Bool func(int x, int y)
{
    int doubled_x = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= x;
        loop invariant doubled_x == 2 * i;
        loop assigns i, doubled_x;
        loop variant x - i;
    */
    while (i < x)
    {
        doubled_x += 2;
        i += 1;
    }

    //@ assert doubled_x == 2 * x;
    //@ assert doubled_x <= 200;

    return doubled_x <= y;
}

int main()
{
    return 0;
}
