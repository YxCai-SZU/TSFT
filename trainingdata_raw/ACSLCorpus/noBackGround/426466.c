/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (m) && (m) <= 20);
    ensures (1 <= n && n <= 9) ==> \result == m * 2;
    ensures (n == 10 || n == 11 || n == 12) ==> \result == m * 4;
    ensures (n >= 13 && n <= 20) ==> \result == m * 8;
    ensures 2 <= \result <= 160;
*/
int func(int n, int m)
{
    int result;
    
    if (1 <= n && n <= 9) {
        //@ assert 1 <= m && m <= 20;
        //@ assert m * 2 >= 2;
        //@ assert m * 2 <= 40;
        result = m * 2;
    } else if (n == 10 || n == 11 || n == 12) {
        //@ assert 1 <= m && m <= 20;
        //@ assert m * 4 >= 4;
        //@ assert m * 4 <= 80;
        result = m * 4;
    } else {
        //@ assert 1 <= m && m <= 20;
        //@ assert m * 8 >= 8;
        //@ assert m * 8 <= 160;
        result = m * 8;
    }
    
    return result;
}
