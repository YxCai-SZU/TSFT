/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == a * n || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int max_val;
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert a * n <= 50 * 20;
    
    if (a * n > b) {
        max_val = b;
    } else {
        max_val = a * n;
    }
    
    //@ assert max_val == a * n || max_val == b;
    //@ assert max_val <= b;
    return max_val;
}
