/*@
    requires (0 <= (a) && (a) < 256) && (0 <= (b) && (b) < 256);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    //@ assert (0 <= (a) && (a) < 256) && (0 <= (b) && (b) < 256);
    //@ assert ((a) * (b)) <= 65535;
    result = a * b;
    //@ assert result == ((a) * (b));
    return result;
}
