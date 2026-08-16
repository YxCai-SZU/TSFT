/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123;
    requires 0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
    requires is_ordered(a, b, c, d, e);
    ensures \result == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
*/
int func(int a, int b, int c, int d, int e, int k)
{
    int answer;
    answer = 0;

    //@ assert a < b && b < c && c < d && d < e;

    if (b - a <= k)
    {
        answer = 1;
    }
    if (c - a <= k)
    {
        answer = 1;
    }
    if (d - a <= k)
    {
        answer = 1;
    }
    if (e - a <= k)
    {
        answer = 1;
    }

    //@ assert answer == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
    return answer;
}
