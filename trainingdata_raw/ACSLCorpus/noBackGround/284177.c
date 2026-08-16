/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int ans;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    ans = a * b;
    //@ assert ans == ((a) * (b));
    return ans;
}
