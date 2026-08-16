/*@
    requires (400 <= (X) && (X) <= 1999);
    ensures \result == 10 - (X - 400) / 200;
    assigns \nothing;
*/
int func(int X)
{
    int result;
    int temp;
    int count;

    result = 0;
    temp = X - 400;
    count = 0;

    /*@
        loop invariant (400 <= (X) && (X) <= 1999);
        loop invariant ((temp) >= 0);
        loop invariant ((temp) == (X) - 400 - 200 * (count));
        loop invariant ((count) >= 0 && (count) <= ((X) - 400) / 200);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 200)
    {
        //@ assert temp >= 200;
        temp -= 200;
        count += 1;
    }

    //@ assert count == (X - 400) / 200;
    result = 10 - count;
    return result;
}
