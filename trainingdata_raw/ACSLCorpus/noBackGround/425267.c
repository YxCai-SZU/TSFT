/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((((a)) * ((b))) - (((a)) + ((b)) - 1));
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int x;
    unsigned int y;
    int result;

    //@ assert (2 <= (a) && (a) <= 100 &&         2 <= (b) && (b) <= 100);
    //@ assert ((a) + (b) - 1) <= 199;
    //@ assert ((a) * (b)) <= 10000;
    //@ assert ((a) * (b)) >= ((a) + (b) - 1);

    x = a + b - 1;
    y = a * b;
    result = (int)y - (int)x;

    //@ assert result == ((((a)) * ((b))) - (((a)) + ((b)) - 1));
    return result;
}
