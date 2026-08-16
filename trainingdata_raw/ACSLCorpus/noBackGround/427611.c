/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures ((m) <= 10) ==> \result == n * m;
    ensures ((m) > 10) ==> \result == -1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (m <= 10)
    {
        //@ assert ((m) <= 10);
        //@ assert 1 <= n && n <= 20;
        //@ assert 1 <= m && m <= 10;
        //@ assert n * m <= 200;
        result = n * m;
    }
    else
    {
        //@ assert ((m) > 10);
        result = -1;
    }

    //@ assert ((m) <= 10) ==> result == n * m;
    //@ assert ((m) > 10) ==> result == -1;
    return result;
}
