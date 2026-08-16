/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (b) == (c)) ==> \result == 1;
    ensures ((a) != (b) && (b) != (c) && (a) != (c)) ==> \result == 3;
    ensures (((a) == (b) && (b) != (c)) || ((a) != (b) && (b) == (c)) || ((a) == (c) && (a) != (b))) ==> \result == 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    ans = -1;

    if (a == b && b == c)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else if (a != b && b != c && a != c)
    {
        ans = 3;
        //@ assert ans == 3;
    }
    else
    {
        ans = 2;
        //@ assert ans == 2;
    }

    return ans;
}
