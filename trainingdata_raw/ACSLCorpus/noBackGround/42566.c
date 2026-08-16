/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (r) && (r) <= 4111);
    ensures \result == ((r) + (((n)) >= 10 ? 0 : 100 * (10 - ((n)))));
    assigns \nothing;
*/
int func(int n, int r)
{
    int max_val;
    int ans;

    //@ assert (1 <= (n) && (n) <= 100 &&         0 <= (r) && (r) <= 4111);
    
    if (n >= 10) {
        max_val = 0;
    } else {
        max_val = 100 * (10 - n);
    }
    
    ans = r + max_val;
    
    //@ assert ans == ((r) + (((n)) >= 10 ? 0 : 100 * (10 - ((n)))));
    
    return ans;
}
