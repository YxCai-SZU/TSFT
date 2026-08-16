/*@
    requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == 1 <==> ((d) <= (s) * (t));
*/
int func(int d, int t, int s)
{
    //@ assert 1 <= d <= 10000;
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert 1 <= s * t <= 10000 * 10000;
    
    if (d <= s * t)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
