/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int func(int n, int k)
{
    //@ assert (1 <= (k) <= (n) <= 50);
    //@ assert ((n) - (k) + 1) >= 1;
    //@ assert ((n) - (k) + 1) <= 50;
    return n - k + 1;
}
