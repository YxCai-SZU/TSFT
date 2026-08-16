/*@
    requires -1000 <= x <= 1000;
    ensures \result == -1 || \result == 0 || \result == 1;
    ensures \result == -1 ==> x < 0;
    ensures \result == 0 ==> x == 0;
    ensures \result == 1 ==> x > 0;
*/
int func(int x)
{
    int result;
    
    if (x < 0)
    {
        //@ assert ((x) < 0);
        result = -1;
    }
    else if (x == 0)
    {
        //@ assert ((x) == 0);
        result = 0;
    }
    else
    {
        //@ assert ((x) > 0);
        result = 1;
    }
    
    return result;
}
