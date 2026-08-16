/*@
    requires (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    ensures \result >= 1;
    ensures \result <= n + m;
    ensures n + m == 1 ==> \result == 1;
    ensures n + m > 1 ==> \result == n + m - 1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    
    if (n + m == 1) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = n + m - 1;
        //@ assert result == n + m - 1;
    }
    
    //@ assert result >= 1;
    //@ assert result <= n + m;
    //@ assert n + m == 1 ==> result == 1;
    //@ assert n + m > 1 ==> result == n + m - 1;
    
    return result;
}
