/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x / 100 * 5) >= x;
    ensures \result == 0 ==> (x / 100 * 5) < x;
*/
int func(int x)
{
    int n;
    int temp_x;
    int count;
    int i;
    int n2;

    n = 0;
    temp_x = x;
    count = 0;

    /*@
        loop invariant (1 <= (x) <= 100000);
        loop invariant (0 <= (temp_x) <= (x) && (temp_x) == (x) - 100 * (count));
        loop invariant ((count) >= 0 && (count) <= (x) / 100);
        loop assigns temp_x, count;
    */
    while (temp_x >= 100)
    {
        //@ assert temp_x >= 100;
        temp_x -= 100;
        count += 1;
    }
    n = count * 5;

    i = 0;
    n2 = 0;
    /*@
        loop invariant (1 <= (x) <= 100000);
        loop invariant (0 <= (i) <= (n) && (n2) == 5 * (i));
        loop invariant ((count) >= 0 && (count) <= (x) / 100);
        loop assigns i, n2;
    */
    while (i < n)
    {
        //@ assert i < n;
        n2 += 5;
        i += 1;
    }

    if (n2 >= x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
