/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
    ensures ((\result) >= (a) && (\result) >= (b) && (\result) >= (c) && (\result) >= (d) &&
        ((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d)));
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    
    if (a > b)
    {
        max_ab = a;
    }
    else
    {
        max_ab = b;
    }
    
    if (c > d)
    {
        max_cd = c;
    }
    else
    {
        max_cd = d;
    }
    
    if (max_ab > max_cd)
    {
        max_cd = max_ab;
    }
    
    //@ assert max_cd >= a && max_cd >= b && max_cd >= c && max_cd >= d;
    //@ assert max_cd == a || max_cd == b || max_cd == c || max_cd == d;
    
    return max_cd;
}
