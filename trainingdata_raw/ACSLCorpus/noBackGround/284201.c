/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int ans;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    ans = a * b;

    //@ assert ans == ((a) * (b));
    return ans;
}
