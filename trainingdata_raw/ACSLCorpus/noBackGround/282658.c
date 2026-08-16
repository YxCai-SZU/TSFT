/*@
    requires (0 <= (X) <= 1);
    ensures (((X) == 1 ==> (\result) == 0) && ((X) == 0 ==> (\result) == 1));
*/
int func(int X)
{
    int result;

    //@ assert (0 <= (X) <= 1);

    if (X == 1)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }

    //@ assert (((X) == 1 ==> (result) == 0) && ((X) == 0 ==> (result) == 1));

    return result;
}
