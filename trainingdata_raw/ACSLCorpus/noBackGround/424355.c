/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 20) && (1 <= (c) && (c) <= 2000);
    ensures (0 <= (\result) && (\result) <= (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 20);
    //@ assert (1 <= (c) && (c) <= 2000);
    
    //@ assert 1 <= a * b && a * b <= 2000;
    int ans = a * b;
    
    if (ans > c) {
        ans = c;
    }
    
    //@ assert 0 <= ans;
    //@ assert ans <= c;
    return ans;
}
