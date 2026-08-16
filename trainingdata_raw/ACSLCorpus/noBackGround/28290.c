/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * r * 314) / 100;
*/
int func(int r)
{
    int pi_approx;
    int scale;
    int scaled_r;
    int ans;
    int temp;

    pi_approx = 314;
    scale = 100;
    scaled_r = r * scale;
    ans = 0;
    temp = 2 * pi_approx * r;

    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi_approx) == 314 &&
        (scale) == 100 &&
        (scaled_r) == (r) * (scale) &&
        0 <= (ans) <= (2 * (pi_approx) * (r)) / (scale) &&
        (temp) == 2 * (pi_approx) * (r) - (ans) * (scale));
        loop assigns temp, ans;
        loop variant ((temp));
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp -= scale;
        ans += 1;
    }

    //@ assert ans == (2 * r * 314) / 100;
    return ans;
}
