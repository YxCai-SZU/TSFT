/*@
    requires (1 <= (a) <= 100);
    ensures \result == a * (1 + a + a * a);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int result;
    //@ assert 1 <= a && a <= 100;
    //@ assert a * (1 + a + a * a) <= 100 * (1 + 100 + 100 * 100);
    result = a * (1 + a + a * a);
    return result;
}
