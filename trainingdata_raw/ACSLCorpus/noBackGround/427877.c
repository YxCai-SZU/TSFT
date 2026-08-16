/*@
    requires ((x) == 15 || (x) == 30);
    ensures (((x) == 15 ==> (\result) == 15) &&
        ((x) == 30 ==> (\result) == 30));
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int result;

    if (x == 15)
    {
        result = 15;
        //@ assert result == 15;
    }
    else
    {
        result = 30;
        //@ assert result == 30;
    }

    //@ assert (((x) == 15 ==> (result) == 15) &&         ((x) == 30 ==> (result) == 30));
    return result;
}
