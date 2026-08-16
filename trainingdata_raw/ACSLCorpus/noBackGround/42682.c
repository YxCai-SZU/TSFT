/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (((1 <= ((a)) <= 9) && (1 <= ((b)) <= 9)) ==> \result == ((a) * (b))) &&
            ((!(1 <= ((a)) <= 9) || !(1 <= ((b)) <= 9)) ==> \result == -1);
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_val;
    int result;

    max_val = (a > b) ? a : b;

    //@ assert max_val == ((a > b) ? a : b);

    if (max_val <= 9)
    {
        //@ assert ((1 <= ((a)) <= 9) && (1 <= ((b)) <= 9));
        //@ assert ((a) * (b)) <= 81;
        result = a * b;
        return result;
    }
    else
    {
        //@ assert (!(1 <= ((a)) <= 9) || !(1 <= ((b)) <= 9));
        return -1;
    }
}
