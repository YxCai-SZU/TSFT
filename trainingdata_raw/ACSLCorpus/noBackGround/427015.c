/*@
    requires ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100));
    ensures ((\result) >= 0 && (\result) <= (b) &&
        ((a) > (b) ==> (\result) == 0) && ((a) <= (b) ==> (\result) == (b) - (a)));
*/
int func(int a, int b)
{
    int result;

    //@ assert ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100));
    if (a > b)
    {
        //@ assert a > b;
        result = 0;
    }
    else
    {
        //@ assert a <= b;
        result = b - a;
    }
    //@ assert ((result) >= 0 && (result) <= (b) &&         ((a) > (b) ==> (result) == 0) && ((a) <= (b) ==> (result) == (b) - (a)));
    return result;
}
