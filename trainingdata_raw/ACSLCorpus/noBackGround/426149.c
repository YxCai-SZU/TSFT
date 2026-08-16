/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures (a == b && b != c) ==> \result == c;
    ensures (b == c && a != b) ==> \result == a;
    ensures (a == c && a != b) ==> \result == b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    
    if (a == b)
    {
        ans = c;
        //@ assert a == b && ans == c;
    }
    else if (b == c)
    {
        ans = a;
        //@ assert b == c && a != b && ans == a;
    }
    else
    {
        ans = b;
        //@ assert !(a == b) && !(b == c) && ans == b;
    }
    
    //@ assert ans == (((a) == (b) && (b) != (c)) ? (c) :         ((b) == (c) && (a) != (b)) ? (a) :         (b));
    return ans;
}
