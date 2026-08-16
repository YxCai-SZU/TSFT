/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b)) / 100);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100);
    //@ assert a * b <= 10000;

    result = (a * b) / 100;
    return result;
}
