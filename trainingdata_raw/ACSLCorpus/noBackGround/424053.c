/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    unsigned int result;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert 1 <= a && a <= 10;

    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;

    a1 = a;
    a2 = a * a;
    a3 = a * a * a;

    //@ assert a1 + a2 + a3 <= 1110;

    result = a1 + a2 + a3;
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return result;
}
