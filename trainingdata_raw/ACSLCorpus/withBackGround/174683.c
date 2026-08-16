/*@
    predicate valid_range(integer n) = 1 <= n <= 1000;
    predicate first_loop_invariant(integer n, integer temp_n, integer count) =
        0 <= temp_n <= n &&
        0 <= count <= n / 3 &&
        temp_n == n - 3 * count;
    predicate second_loop_invariant(integer n, integer i, integer ans, integer count) =
        0 <= i <= count &&
        0 <= ans <= i &&
        ans == i &&
        count <= n / 3 &&
        i <= n / 3;
    lemma count_non_negative: \forall integer n, temp_n, count; valid_range(n) && first_loop_invariant(n, temp_n, count) ==> count >= 0;
*/

/*@
    requires valid_range(n);
    ensures \result >= 0;
    ensures \result * 3 <= n;
*/
int func(int n)
{
    int temp_n;
    int count;
    int ans;
    int i;

    temp_n = n;
    count = 0;

    /*@
        loop invariant first_loop_invariant(n, temp_n, count);
        loop assigns temp_n, count;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n -= 3;
        count += 1;
    }

    ans = 0;
    i = 0;

    /*@
        loop invariant second_loop_invariant(n, i, ans, count);
        loop assigns ans, i;
    */
    while (i < count)
    {
        //@ assert i < count;
        ans += 1;
        i += 1;
    }

    //@ assert ans >= 0;
    //@ assert ans * 3 <= n;
    return ans;
}
