/*@
    requires 1 <= x && x <= 32;
    requires 1 <= y && y <= 32;
    ensures \result <= 32 * 32;
    ensures \result >= x * y;
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int res;

    //@ assert (1 <= (x) && (x) <= 32 && 1 <= (y) && (y) <= 32);
    //@ assert x * y <= 32 * 32;
    //@ assert x * y >= 1;

    res = x * y;
    return res;
}
