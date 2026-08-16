/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp;
    int count;
    result = 0;
    temp = n + 1;
    count = 0;

    /*@
        loop invariant (1 <= (n) && (n) <= 100 &&
        0 <= (temp) && (temp) <= (n) + 1 &&
        0 <= (count) && (count) <= ((n) + 1) / 2 &&
        (temp) == (n) + 1 - 2 * (count) &&
        ((count) > 0 ==> (result) == 0));
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == (((n) + 1) / 2);
    return result;
}
