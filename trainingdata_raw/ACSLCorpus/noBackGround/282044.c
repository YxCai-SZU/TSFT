/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
int func(int n, int k, int x, int y)
{
    int ans;
    
    //@ assert n * x <= 100000000;
    //@ assert k * x + (n - k) * y <= 200000000;
    
    if (n <= k) {
        ans = n * x;
    } else {
        ans = k * x + (n - k) * y;
    }
    
    return ans;
}
