/*@
    requires 0 <= A <= 100;
    requires 0 <= B <= 100;
    requires 0 <= C <= 100;
    ensures \result == 1 <==> ((A) + (B) + (C) < 0);
*/
int func(int A, int B, int C)
{
    int result;
    //@ assert 0 <= A <= 100;
    //@ assert 0 <= B <= 100;
    //@ assert 0 <= C <= 100;
    
    if (A + B + C < 0)
    {
        //@ assert ((A) + (B) + (C) < 0);
        result = 1;
    }
    else
    {
        //@ assert !((A) + (B) + (C) < 0);
        result = 0;
    }
    
    return result;
}
