/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
int func(long long a, long long p)
{
    long long sum;
    long long ans;
    int is_even;

    sum = a * 3 + p;
    ans = 0;
    is_even = 1;

    /*@
        loop invariant 0 <= sum <= ((a) * 3 + (p));
        loop invariant ans >= 0;
        loop invariant ans <= (((a) * 3 + (p)) - sum) / 2;
        loop invariant ((a) * 3 + (p)) == sum + 2 * ans;
        loop assigns sum, ans, is_even;
    */
    while (sum >= 2)
    {
        sum -= 2;
        ans += 1;
    }

    //@ assert ans <= ((a) * 3 + (p));

    return ans;
}
