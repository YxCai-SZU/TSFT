/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a > b ? (a > c ? a : c) : (b > c ? b : c));

    logic integer calculate_ans(integer a, integer b, integer c, integer m) =
        (m == a ? b + c : (m == b ? a + c : a + b));

    lemma ans_in_range:
        \forall integer a, b, c, m, ans;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        m == max_of_three(a, b, c) &&
        ans == calculate_ans(a, b, c, m) ==>
        ans >= 2 && ans <= 22;

    lemma ans_correct:
        \forall integer a, b, c, m, ans;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        m == max_of_three(a, b, c) &&
        ans == calculate_ans(a, b, c, m) ==>
        ans == a + b || ans == b + c || ans == c + a;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == a + b || \result == b + c || \result == c + a;
    ensures \result >= 2 && \result <= 22;
*/
int func(int a, int b, int c)
{
    int m;
    int ans;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    if (a > b)
    {
        m = a;
    }
    else
    {
        m = b;
    }

    //@ assert m == (a > b ? a : b);

    if (m > c)
    {
        /* skip */
    }
    else
    {
        m = c;
    }

    //@ assert m == max_of_three(a, b, c);

    if (m == a)
    {
        ans = b + c;
    }
    else if (m == b)
    {
        ans = a + c;
    }
    else
    {
        ans = a + b;
    }

    //@ assert ans == calculate_ans(a, b, c, m);
    //@ assert ans >= 2 && ans <= 22;

    return ans;
}
