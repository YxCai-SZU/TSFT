/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures ((\result) <= (a) &&
        (\result) >= 0 &&
        ((\result) == (a) - (b) * 2 || (\result) == 0));
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);

    if (a > b * 2)
    {
        //@ assert a - b * 2 <= a && a - b * 2 >= 0;
        result = a - b * 2;
    }
    else
    {
        //@ assert 0 <= a && 0 >= 0;
        result = 0;
    }

    //@ assert ((result) <= (a) &&         (result) >= 0 &&         ((result) == (a) - (b) * 2 || (result) == 0));
    return result;
}
