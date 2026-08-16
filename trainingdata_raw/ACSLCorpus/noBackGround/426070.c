/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    requires a != b;
    ensures \result == 1 <==> ((c) == (a) || (c) == (b) || (c) == (a) + 1 || (c) == (b) + 1);
*/
_Bool func(unsigned int a, unsigned int b, unsigned int c)
{
    _Bool ans = 0;
    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    //@ assert a != b;

    if (c == a || c == b)
    {
        ans = 1;
    }
    else if (c == a + 1 || c == b + 1)
    {
        ans = 1;
    }

    //@ assert ans == 1 <==> ((c) == (a) || (c) == (b) || (c) == (a) + 1 || (c) == (b) + 1);
    return ans;
}
