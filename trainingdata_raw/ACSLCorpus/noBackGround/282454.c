/*@
    requires (1 <= (m1) && (m1) <= 12) && (1 <= (m2) && (m2) <= 12);
    requires m1 < m2;
    ensures \result == 1 ==> ((m2) == (m1) + 1);
    ensures \result == 0 ==> !((m2) == (m1) + 1);
*/
int func(long m1, long d1, long m2, long d2)
{
    int result;

    if (m2 == m1 + 1)
    {
        result = 1;
        //@ assert ((m2) == (m1) + 1);
    }
    else
    {
        //@ assert !((m2) == (m1) + 1);
        result = 0;
    }

    return result;
}
