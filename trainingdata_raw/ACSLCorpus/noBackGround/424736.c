/*@
    requires (-100 <= (k) && (k) <= 100);
    ensures (k >= 0 ==> \result == ((k) * 8));
    ensures (k < 0 ==> \result == 0);
    assigns \nothing;
*/
int func(int k)
{
    int result;
    //@ assert (-100 <= (k) && (k) <= 100);
    if (k < 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert ((k) >= 0);
        //@ assert k <= 100;
        //@ assert 0 <= ((k) * 8);
        //@ assert ((k) * 8) <= 800;
        result = k * 8;
        //@ assert result == ((k) * 8);
    }
    return result;
}
