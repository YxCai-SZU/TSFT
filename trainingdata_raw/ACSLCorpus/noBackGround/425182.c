/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
*/
long func(long a, long b, long c)
{
    long ans = 0;
    long a_copy = a;
    long b_copy = b;
    long c_copy = c;

    //@ assert a_copy == a && b_copy == b && c_copy == c;

    ans += (a_copy < b_copy) ? a_copy : b_copy;

    if (c_copy < b_copy)
    {
        long left = b_copy - c_copy;
        //@ assert left >= 0;
        if (left < a_copy)
        {
            ans += left;
        }
        else
        {
            ans += a_copy;
        }
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c;

    return ans;
}
