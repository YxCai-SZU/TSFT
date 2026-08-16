/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (r) && (r) <= 4111);
    ensures \result == r + 100 * (10 - n) || \result == r;
*/
int func(int n, int r)
{
    int max_val;
    int result;

    //@ assert (1 <= (n) && (n) <= 100 &&         0 <= (r) && (r) <= 4111);
    
    if (10 - n > 0) {
        max_val = 10 - n;
    } else {
        max_val = 0;
    }
    
    //@ assert max_val == ((10 - (n)) > 0 ? (10 - (n)) : 0);
    
    result = r + 100 * max_val;
    
    //@ assert result == r + 100 * ((10 - (n)) > 0 ? (10 - (n)) : 0);
    //@ assert result == r + 100 * (10 - n) || result == r;
    
    return result;
}
