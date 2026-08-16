/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result <= ((a) * 3 + (p));
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned long func(unsigned long a, unsigned long p)
{
    unsigned long sum_pieces;
    unsigned long result;
    unsigned long i;

    sum_pieces = a * 3 + p;
    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= sum_pieces;
        loop invariant result >= 0;
        loop invariant result <= i / 2;
        loop invariant sum_pieces == a * 3 + p;
        loop assigns i, result;
        loop variant sum_pieces - i;
    */
    while (i < sum_pieces)
    {
        if (i + 2 < sum_pieces)
        {
            //@ assert i + 2 < sum_pieces;
            result += 1;
            i += 2;
        }
        else
        {
            //@ assert i + 2 >= sum_pieces;
            break;
        }
    }

    //@ assert result <= ((a) * 3 + (p));
    //@ assert result >= 0;
    return result;
}
