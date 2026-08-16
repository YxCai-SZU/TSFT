/*@
    requires 0 <= X <= 9;
    requires 0 <= A <= 9;
    ensures ((X) < (A)) ==> \result == 0;
    ensures ((X) >= (A)) ==> \result == 10;
*/
int func(int X, int A)
{
    int result;
    //@ assert 0 <= X <= 9;
    //@ assert 0 <= A <= 9;
    
    if (X < A)
    {
        //@ assert ((X) < (A));
        result = 0;
    }
    else
    {
        //@ assert ((X) >= (A));
        result = 10;
    }
    
    return result;
}
