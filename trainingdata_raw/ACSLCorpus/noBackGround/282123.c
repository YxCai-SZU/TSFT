/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (c) <= 20);
    ensures \result <= 2 * (a * b + b * c + a * c);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ab;
    unsigned int bc;
    unsigned int ac;
    unsigned int max1;
    unsigned int max2;

    //@ assert a * b <= 400;
    ab = a * b;

    //@ assert b * c <= 400;
    bc = b * c;

    //@ assert a * c <= 400;
    ac = a * c;

    //@ assert ab + bc <= 800;

    //@ assert ab + bc + ac <= 1200;

    max1 = (ab > bc) ? ab : bc;
    max2 = (max1 > ac) ? max1 : ac;

    //@ assert max2 <= 400;

    //@ assert ab + bc + ac <= 1200;

    return max2;
}
