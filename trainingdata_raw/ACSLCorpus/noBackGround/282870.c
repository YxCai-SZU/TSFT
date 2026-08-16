/*@
    requires (1 <= (k) && (k) <= 100);
    requires (1 <= (x) && (x) <= 100000);
    ensures ((\result) == ((k) * 500 >= (x)));
    assigns \nothing;
*/
int func(unsigned int k, unsigned int x)
{
    // Variable declarations at the top
    int result;

    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    //@ assert k * 500 <= 100 * 500;
    //@ assert k * 500 >= 1 * 500;

    result = (k * 500 >= x);
    return result;
}
