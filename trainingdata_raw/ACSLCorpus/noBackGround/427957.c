/*@
    requires 1 <= n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) * (n)) >= 1 && ((n) * (n)) <= 10000;
    //@ assert ((n) * (n)) == n * n;
    return n * n;
}
