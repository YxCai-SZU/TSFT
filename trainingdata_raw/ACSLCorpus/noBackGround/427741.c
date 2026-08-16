/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        1 <= (i) && (i) <= (n) &&
        1 <= (j) && (j) <= (m));
    ensures \result == (((n) - (i)) * ((m) - (j)));
    assigns \nothing;
*/
int func(int n, int m, int i, int j)
{
    //@ assert n >= 1 && n <= 100;
    //@ assert m >= 1 && m <= 100;
    //@ assert i >= 1 && i <= n;
    //@ assert j >= 1 && j <= m;
    
    //@ assert (n - i) * (m - j) >= 0;
    //@ assert (n - i) * (m - j) <= 99 * 99;
    
    return (n - i) * (m - j);
}
