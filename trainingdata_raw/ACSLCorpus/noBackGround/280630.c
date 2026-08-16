/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 1 ==> (\result) == 0) && ((x) == 0 ==> (\result) == 1));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert 0 <= x <= 1;
    
    if (x == 1) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert (((x) == 1 ==> (result) == 0) && ((x) == 0 ==> (result) == 1));
    //@ assert result == 0 || result == 1;
    
    return result;
}
