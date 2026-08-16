/*@
    requires (1 <= (k) && (k) <= 100);
    ensures (0 <= (\result) && (\result) <= 10000);
    assigns \nothing;
*/
int func(int k)
{
    int result = 0;
    int i = 1;
    /*@
        loop invariant ((1 <= ((k)) && ((k)) <= 100) && 1 <= (i) && (i) <= 10001 && (0 <= ((result)) && ((result)) <= 10000));
        loop assigns i, result;
        loop variant 10001 - i;
    */
    while (i < 10001)
    {
        int remainder = k;
        /*@
            loop invariant (0 <= (remainder) && (remainder) <= (k));
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= i)
        {
            remainder -= i;
        }
        //@ assert remainder >= 0 && remainder <= k;
        if (remainder == 0)
        {
            result = i;
            break;
        }
        i += 1;
    }
    //@ assert (0 <= (result) && (result) <= 10000);
    return result;
}

int main()
{
    return 0;
}
