/*@
requires 0 <= x <= 1;
ensures \result == 1 - x;
assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert 0 <= x <= 1;
    
    if (x == 0) {
        //@ assert x == 0;
        result = 1;
    } else {
        //@ assert x == 1;
        result = 0;
    }
    
    //@ assert result == 1 - x;
    return result;
}
