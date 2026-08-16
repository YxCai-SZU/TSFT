/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0 && (\result) <= (b));
    ensures (((a) >= (b) ==> (\result) == 0) && ((a) < (b) ==> (\result) == (b) - (a)));
*/
int func(int a, int b)
{
    int min_val;
    int result;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    
    if (a < b)
    {
        min_val = a;
    }
    else
    {
        min_val = b;
    }
    
    //@ assert min_val == (a < b ? a : b);
    
    result = b - min_val;
    
    //@ assert ((result) >= 0 && (result) <= (b));
    //@ assert (((a) >= (b) ==> (result) == 0) && ((a) < (b) ==> (result) == (b) - (a)));
    
    return result;
}
