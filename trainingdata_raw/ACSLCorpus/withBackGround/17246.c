/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    predicate loop_inv(integer r, integer pi, integer ans, integer temp, integer count) =
        1 <= r && r <= 100 &&
        pi == 3142 &&
        ans == (2 * r * pi - temp) / 1000 &&
        temp >= 0 &&
        temp + 1000 * ans == 2 * r * pi &&
        count == (2 * r * pi - temp) / 1000;
    logic integer target_result(integer r) = 2 * r * 3142 / 1000;
*/

/*@
    requires valid_range(r);
    ensures \result == target_result(r);
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int ans;
    int temp;
    int count;

    pi = 3142;
    ans = 0;
    temp = 2 * r * pi;
    count = 0;

    /*@
        loop invariant loop_inv(r, pi, ans, temp, count);
        loop assigns temp, ans, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        //@ assert temp >= 1000;
        temp -= 1000;
        ans += 1;
        count += 1;
    }

    //@ assert ans == target_result(r);
    return ans;
}
