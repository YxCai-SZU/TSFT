/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (k) && (k) <= 100);
    ensures \result == (((n) - 1) * ((k) - 1));
    assigns \nothing;
*/
int func(int n, int k)
{
    //@ assert n > 1;
    //@ assert k > 1;
    //@ assert n <= 100;
    //@ assert k <= 100;
    
    //@ assert n - 1 >= 1;
    //@ assert k - 1 >= 1;
    //@ assert (n - 1) * (k - 1) <= 99 * 99;
    
    int ans = (n - 1) * (k - 1);
    return ans;
}
