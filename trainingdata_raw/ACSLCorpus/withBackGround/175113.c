/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;

    predicate is_candidate(integer res, integer a, integer b, integer c, integer d) =
        res == a || res == b || res == c || res == d;

    predicate is_maximum(integer res, integer a, integer b, integer c, integer d) =
        res >= a || res >= b || res >= c || res >= d;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
    ensures is_candidate(\result, a, b, c, d);
    ensures is_maximum(\result, a, b, c, d);
*/
long func(long a, long b, long c, long d)
{
    long max_val;
    int i;

    max_val = a;
    i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant max_val == a || max_val == b;
        loop invariant i == 0 ==> max_val == a;
        loop invariant i == 1 ==> max_val >= a && max_val >= b;
        loop invariant is_in_range(a) && is_in_range(b);
        loop assigns max_val, i;
    */
    while (i < 1)
    {
        //@ assert max_val == a || max_val == b;
        if (b > max_val)
        {
            max_val = b;
        }
        i += 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant max_val == a || max_val == b || max_val == c;
        loop invariant i == 0 ==> max_val >= a && max_val >= b;
        loop invariant i == 1 ==> max_val >= a && max_val >= b && max_val >= c;
        loop invariant is_in_range(a) && is_in_range(b) && is_in_range(c);
        loop assigns max_val, i;
    */
    while (i < 1)
    {
        //@ assert max_val == a || max_val == b || max_val == c;
        if (c > max_val)
        {
            max_val = c;
        }
        i += 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant max_val == a || max_val == b || max_val == c || max_val == d;
        loop invariant i == 0 ==> max_val >= a && max_val >= b && max_val >= c;
        loop invariant i == 1 ==> max_val >= a && max_val >= b && max_val >= c && max_val >= d;
        loop invariant is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
        loop assigns max_val, i;
    */
    while (i < 1)
    {
        //@ assert max_val == a || max_val == b || max_val == c || max_val == d;
        if (d > max_val)
        {
            max_val = d;
        }
        i += 1;
    }

    //@ assert is_candidate(max_val, a, b, c, d);
    //@ assert is_maximum(max_val, a, b, c, d);
    return max_val;
}
