/*@
    requires 1 <= a && a < b && b < 100;
    ensures \result == b - a;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result = 0;
    unsigned int i = a;

    /*@
        loop invariant a <= i && i <= b;
        loop invariant result == ((i) - (a));
        loop invariant (1 <= (a) && (a) < (b) && (b) < 100);
        loop invariant i < 100;
        loop invariant result < 100;
        loop assigns result, i;
    */
    while (i < b)
    {
        //@ assert i > a ==> result == i - a;
        result += 1;
        i += 1;
    }

    //@ assert result == b - a;
    return result;
}
