/*@
    predicate in_range(integer v) = 1 <= v <= 10000;
    predicate condition_holds(integer d, integer t, integer s) = d <= t * s;
    logic integer safe_mult(integer a, integer b) = a * b;
    lemma mult_bounds: \forall integer t, s; in_range(t) && in_range(s) ==> safe_mult(t, s) <= 100000000;
*/

/*@
    requires in_range(d) && in_range(t) && in_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
_Bool func(long long d, long long t, long long s)
{
    long long tmp;
    _Bool ans;
    //@ assert in_range(t);
    //@ assert in_range(s);
    //@ assert t * s <= 10000 * 10000;
    tmp = t * s;
    if (d <= tmp)
        ans = 1;
    else
        ans = 0;
    return ans;
}

int main()
{
    long long d;
    long long t;
    long long s;
    _Bool result;
    d = 10;
    t = 5;
    s = 2;
    result = func(d, t, s);
    //@ assert result ==> condition_holds(d, t, s);
    //@ assert !result ==> !condition_holds(d, t, s);
    return 0;
}
