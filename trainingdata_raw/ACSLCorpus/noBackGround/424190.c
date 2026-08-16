/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == (((a) * 2 * 3 * 5 + (b) * 5) / 10);
*/
int func(int a, int b)
{
    int result;
    int temp;
    int count;

    result = 0;
    temp = a * 2 * 3 * 5 + b * 5;
    count = 0;

    /*@
        loop invariant (1 <= (a) && (a) <= 100);
        loop invariant (1 <= (b) && (b) <= 100);
        loop invariant ((temp) >= 0);
        loop invariant ((temp) == (a) * 2 * 3 * 5 + (b) * 5 - 10 * (count));
        loop invariant ((count) >= 0);
        loop assigns temp, count;
    */
    while (temp >= 10)
    {
        temp -= 10;
        count += 1;
    }

    result = count;

    //@ assert result == (((a) * 2 * 3 * 5 + (b) * 5) / 10);

    return result;
}
