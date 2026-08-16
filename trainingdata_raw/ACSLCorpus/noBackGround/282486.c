/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    result = a * b;
    return result;
}
