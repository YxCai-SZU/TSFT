/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result >= 0;
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
*/
int func(int a, int b)
{
    int m;
    int ans;

    m = (a < b) ? a : b;
    //@ assert m == ((a) < (b) ? (a) : (b));

    if (a + b - m >= m)
    {
        ans = a + b;
        //@ assert ans == a + b;
    }
    else
    {
        ans = 2 * m - 1;
        //@ assert ans == 2 * m - 1;
    }

    //@ assert ans == (((a) + (b) - (((a)) < ((b)) ? ((a)) : ((b))) >= (((a)) < ((b)) ? ((a)) : ((b)))) ? ((a) + (b)) : (2 * (((a)) < ((b)) ? ((a)) : ((b))) - 1));
    return ans;
}
