/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == (((n) - 1) / 2);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp;
    int count;

    result = 0;
    temp = n - 1;
    count = 0;

    /*@
        loop invariant 1 <= n <= 1000000000;
        loop invariant temp >= 0;
        loop invariant temp == n - 1 - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= (n - 1) / 2;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    //@ assert count == (((n) - 1) / 2);
    result = count;
    return result;
}
