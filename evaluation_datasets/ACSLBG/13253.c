/*@
    predicate in_range(integer v) = 1 <= v <= 16;
    predicate sum_in_range(integer a, integer b) = a + b <= 16;
    predicate both_small(integer a, integer b) = a <= 8 && b <= 8;
*/


int func(int x, int y)
{
    // Variable declarations at the top of the scope
    int ans;

    //@ assert x + y <= 16;
    //@ assert x + y >= 2;

    if (x <= 8 && y <= 8)
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }

    //@ assert ans == 1 <==> (x <= 8 && y <= 8);
    return ans;
}
