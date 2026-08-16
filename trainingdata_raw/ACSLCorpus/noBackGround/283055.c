/*@
    requires k <= 10000;
    ensures \result == k * k;
    assigns \nothing;
*/
unsigned int func(unsigned int k)
{
    //@ assert (0 <= (k) && (k) <= 10000);
    //@ assert ((k) * (k) <= 10000 * 10000);
    return k * k;
}
