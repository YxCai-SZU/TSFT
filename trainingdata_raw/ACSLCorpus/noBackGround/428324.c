/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    // Variable declarations at the top
    unsigned int result;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert ((x) * (x)) <= 10000;
    result = x * x;
    return result;
}
