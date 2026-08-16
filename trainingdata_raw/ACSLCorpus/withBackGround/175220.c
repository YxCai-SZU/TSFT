/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;
    logic integer sum_bcd(integer a, integer b, integer c, integer d) = b + c + d;
    logic integer sum_cda(integer a, integer b, integer c, integer d) = c + d + a;
    logic integer sum_dab(integer a, integer b, integer c, integer d) = d + a + b;

    lemma min_is_one_of:
        \forall integer s, n, e, w, min;
        (min == s || min == n || min == e || min == w) ==>
        (min == s || min == n || min == e || min == w);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == sum_abc(a,b,c) || \result == sum_bcd(a,b,c,d) ||
            \result == sum_cda(a,b,c,d) || \result == sum_dab(a,b,c,d);
    ensures \result <= 30000;
*/
int func(int a, int b, int c, int d)
{
    int s;
    int n;
    int e;
    int w;
    int min_value;

    s = a + b + c;
    n = b + c + d;
    e = c + d + a;
    w = d + a + b;

    min_value = s;
    //@ assert min_value == s || min_value == n || min_value == e || min_value == w;
    if (n < min_value)
    {
        min_value = n;
        //@ assert min_value == s || min_value == n || min_value == e || min_value == w;
    }
    if (e < min_value)
    {
        min_value = e;
        //@ assert min_value == s || min_value == n || min_value == e || min_value == w;
    }
    if (w < min_value)
    {
        min_value = w;
        //@ assert min_value == s || min_value == n || min_value == e || min_value == w;
    }

    //@ assert min_value == s || min_value == n || min_value == e || min_value == w;
    return min_value;
}
