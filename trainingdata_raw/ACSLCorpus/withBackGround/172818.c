/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h <= 23 &&
        0 <= m && m <= 59;

    predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        h1 < h2 || (h1 == h2 && m1 < m2);

    logic integer total_minutes(integer h, integer m) = h * 60 + m;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires 0 <= k && k <= 23 * 60 + 59;
    requires time_order(h1, m1, h2, m2);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start_minutes;
    int end_minutes;
    int result;

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;
    result = end_minutes - start_minutes - k;

    //@ assert result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;

    return result;
}
