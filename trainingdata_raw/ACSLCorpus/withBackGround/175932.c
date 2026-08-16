/*@
    predicate is_valid_params(integer X, integer Y) =
        1 <= X <= 100 &&
        1 <= Y <= 100 &&
        Y % 2 == 0;

    logic integer half_Y(integer Y) = Y / 2;

    logic integer possible_ans1(integer X, integer Y) = X + half_Y(Y);
    logic integer possible_ans2(integer X, integer Y) = X - half_Y(Y);

    predicate ans_satisfies(integer X, integer Y, integer ans) =
        ans == possible_ans1(X, Y) || ans == possible_ans2(X, Y);
*/

/*@
    requires is_valid_params(X, Y);
    ensures ans_satisfies(X, Y, \result);
*/
long func(long X, long Y)
{
    long ans;
    long temp_Y;
    long count;
    long ans1;
    long ans2;
    long i;

    ans = X;
    temp_Y = Y;
    count = 0;

    /*@
        loop invariant 0 <= temp_Y <= Y;
        loop invariant 0 <= count <= half_Y(Y);
        loop invariant temp_Y == Y - 2 * count;
        loop invariant is_valid_params(X, Y);
        loop assigns temp_Y, count;
    */
    while (temp_Y >= 2)
    {
        temp_Y -= 2;
        count += 1;
    }

    ans1 = X;
    i = 0;
    /*@
        loop invariant 0 <= i <= count;
        loop invariant ans1 == X + i;
        loop invariant 0 <= count <= half_Y(Y);
        loop invariant is_valid_params(X, Y);
        loop assigns ans1, i;
    */
    while (i < count)
    {
        ans1 += 1;
        i += 1;
    }

    ans2 = X;
    i = 0;
    /*@
        loop invariant 0 <= i <= count;
        loop invariant ans2 == X - i;
        loop invariant 0 <= count <= half_Y(Y);
        loop invariant is_valid_params(X, Y);
        loop assigns ans2, i;
    */
    while (i < count)
    {
        ans2 -= 1;
        i += 1;
    }

    //@ assert ans1 == possible_ans1(X, Y);
    //@ assert ans2 == possible_ans2(X, Y);
    
    ans = (ans1 > ans2) ? ans1 : ans2;
    
    //@ assert ans_satisfies(X, Y, ans);
    return ans;
}
