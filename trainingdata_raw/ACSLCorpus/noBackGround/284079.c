/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures ((\result) >= 0 && ((\result) == (n) - (m) || (\result) == 0));
    ensures \result == ((n) >= (m) ? (n) - (m) : 0);
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n));
    
    if (n >= m) {
        result = n - m;
        //@ assert result == n - m;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == n - m || result == 0;
    return result;
}
