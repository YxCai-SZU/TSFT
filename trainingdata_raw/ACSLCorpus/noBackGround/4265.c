/*@
    requires 1 <= L <= 1000;
    ensures \result == (L * L * L) / 27;
    assigns \nothing;
*/
long func(long L)
{
    long result;
    long count;
    long divisor;

    //@ assert 1 <= L && L <= 1000;
    //@ assert L * L <= 1000000;
    //@ assert L * L * L <= 1000000000;

    result = L * L * L;
    count = 0;
    divisor = 27;

    /*@
        loop invariant 0 <= count <= (L * L * L) / 27;
        loop invariant result == (L * L * L) - (count * 27);
        loop invariant 0 <= result;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= divisor)
    {
        result = result - divisor;
        count = count + 1;
    }

    return count;
}
