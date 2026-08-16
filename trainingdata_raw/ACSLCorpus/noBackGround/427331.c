/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a <= 9 && b <= 9) ==> \result == a * b;
    ensures (a > 9 || b > 9) ==> \result == -1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_value;
    int result;
    
    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    
    max_value = (a > b) ? a : b;
    
    //@ assert max_value == ((a) > (b) ? (a) : (b));
    //@ assert 1 <= max_value <= 20;
    
    if (max_value <= 9)
    {
        //@ assert max_value <= 9;
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert a * b <= 81;
        
        result = a * b;
        //@ assert result == a * b;
        return result;
    }
    else
    {
        //@ assert max_value > 9;
        //@ assert a > 9 || b > 9;
        
        result = -1;
        //@ assert result == -1;
        return result;
    }
}
