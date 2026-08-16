/*@
    requires 1 <= n <= 100;
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int func(unsigned int n)
{
    int ans;
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans == 1 || ans == 0;
    return ans;
}
