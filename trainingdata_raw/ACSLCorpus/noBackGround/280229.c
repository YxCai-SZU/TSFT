/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> (unsigned)\result * 8 / 100 == a && (unsigned)\result * 10 / 100 == b;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int i = 0;
    unsigned int x;
    unsigned int y;

    /*@
        loop invariant 0 <= i <= 10000;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
        loop invariant \forall integer j; 0 <= j < i ==> ((j) * 8 / 100) != a || ((j) * 10 / 100) != b;
        loop assigns i, x, y;
        loop variant 10000 - i;
    */
    while (i < 10000)
    {
        x = i * 8 / 100;
        y = i * 10 / 100;

        //@ assert x == ((i) * 8 / 100) && y == ((i) * 10 / 100);

        if (x == a && y == b)
        {
            //@ assert ((i) * 8 / 100) == a && ((i) * 10 / 100) == b;
            return (int)i;
        }

        //@ assert ((i) * 8 / 100) != a || ((i) * 10 / 100) != b;
        i++;
    }

    //@ assert \forall integer j; 0 <= j < 10000 ==> ((j) * 8 / 100) != a || ((j) * 10 / 100) != b;
    return -1;
}
