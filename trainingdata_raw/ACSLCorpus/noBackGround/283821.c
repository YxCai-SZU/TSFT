/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == (((n) - 1) / 2 + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int ans;
    unsigned int temp;
    unsigned int count;

    ans = 0;
    temp = n - 1;
    count = 0;

    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 100000) &&
        (((temp)) >= 0) &&
        (((count)) >= 0) &&
        (temp) + 2 * (count) == (n) - 1);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    ans = count + 1;

    //@ assert ans == (((n) - 1) / 2 + 1);

    return ans;
}
