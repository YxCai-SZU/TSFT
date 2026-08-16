/*@
    requires (3 <= (n) <= 2000 &&
        1 <= (x) <= (n) &&
        1 <= (y) <= (n) &&
        (x) + 1 < (y));
    ensures \result == (((n) - 2) + ((n) - 1) + ((n) - 1) + ((n) - 2));
    assigns \nothing;
*/
int func(int n, int x, int y)
{
    //@ assert 3 <= n <= 2000;
    //@ assert 1 <= x <= n;
    //@ assert 1 <= y <= n;
    //@ assert x + 1 < y;
    
    int result;
    result = (n - 2) + (n - 1) + (n - 1) + (n - 2);
    
    //@ assert result == (((n) - 2) + ((n) - 1) + ((n) - 1) + ((n) - 2));
    return result;
}
