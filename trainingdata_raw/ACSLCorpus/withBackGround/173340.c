/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer max_of_four(integer a, integer b, integer c, integer d) =
        (a + c) >= (a + d) ?
            ((a + c) >= (b + c) ?
                ((a + c) >= (b + d) ? (a + c) : (b + d))
                : ((b + c) >= (b + d) ? (b + c) : (b + d)))
            : ((a + d) >= (b + c) ?
                ((a + d) >= (b + d) ? (a + d) : (b + d))
                : ((b + c) >= (b + d) ? (b + c) : (b + d)));

    lemma ans_is_one_of_four:
        \forall integer a, b, c, d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        (max_of_four(a,b,c,d) == a + c) ||
        (max_of_four(a,b,c,d) == a + d) ||
        (max_of_four(a,b,c,d) == b + c) ||
        (max_of_four(a,b,c,d) == b + d);

    lemma ans_at_least_two:
        \forall integer a, b, c, d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        max_of_four(a,b,c,d) >= 2;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures \result >= 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int ans;

    ans = a + c;
    //@ assert ans == a + c;
    if (a + d > ans)
    {
        ans = a + d;
        //@ assert ans == a + d;
    }
    //@ assert ans == a + c || ans == a + d;
    if (b + c > ans)
    {
        ans = b + c;
        //@ assert ans == b + c;
    }
    //@ assert ans == a + c || ans == a + d || ans == b + c;
    if (b + d > ans)
    {
        ans = b + d;
        //@ assert ans == b + d;
    }
    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    //@ assert ans >= 2;
    return ans;
}
