/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
*/
int func(unsigned int n)
{
    //@ assert (3 <= (n) && (n) <= 100);
    return (int)((n - 2) * 180);
}
