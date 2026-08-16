/*@
    requires 0 <= a <= 50;
    requires 0 <= b <= 50;
    requires 0 <= c <= 50;
    ensures \result >= 0;
    ensures \result <= 2;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 0 ==> ((a) != (b) && (b) != (c) && (c) != (a));
    ensures \result == 2 ==> (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ans = 0;
    //@ assert 0 <= a <= 50 && 0 <= b <= 50 && 0 <= c <= 50;
    if (a == b && b == c)
    {
        ans = 1;
        //@ assert ((a) == (b) && (b) == (c));
    }
    else if (a != b && b != c && c != a)
    {
        ans = 0;
        //@ assert ((a) != (b) && (b) != (c) && (c) != (a));
    }
    else
    {
        ans = 2;
        //@ assert (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)));
    }
    //@ assert ans >= 0 && ans <= 2;
    return ans;
}
