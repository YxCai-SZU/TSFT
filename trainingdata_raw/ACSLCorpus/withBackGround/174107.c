/*@
    predicate bounds(integer a, integer b, integer c, integer d, integer e, integer f, integer g) =
        a >= -1000000000 && a <= 1000000000 &&
        b >= -1000000000 && b <= 1000000000 &&
        c >= -1000000000 && c <= 1000000000 &&
        d >= -1000000000 && d <= 1000000000 &&
        e >= -1000000000 && e <= 1000000000 &&
        f >= -1000000000 && f <= 1000000000 &&
        g >= -1000000000 && g <= 1000000000;

    logic integer sum123(integer a, integer b, integer c) = a + b + c;
    logic integer sum456(integer d, integer e, integer f) = d + e + f;
    logic integer total_sum(integer a, integer b, integer c, integer d, integer e, integer f) = sum123(a,b,c) + sum456(d,e,f);

    lemma sum123_bounds: \forall integer a,b,c; a >= -1000000000 && a <= 1000000000 && b >= -1000000000 && b <= 1000000000 && c >= -1000000000 && c <= 1000000000 ==> sum123(a,b,c) >= -3000000000 && sum123(a,b,c) <= 3000000000;
    lemma sum456_bounds: \forall integer d,e,f; d >= -1000000000 && d <= 1000000000 && e >= -1000000000 && e <= 1000000000 && f >= -1000000000 && f <= 1000000000 ==> sum456(d,e,f) >= -3000000000 && sum456(d,e,f) <= 3000000000;
    lemma total_sum_bounds: \forall integer a,b,c,d,e,f; bounds(a,b,c,d,e,f,0) ==> total_sum(a,b,c,d,e,f) >= -6000000000 && total_sum(a,b,c,d,e,f) <= 6000000000;
*/

/*@
    requires bounds(a,b,c,d,e,f,g);
    ensures \result == (total_sum(a,b,c,d,e,f) == g);
*/
int func(long long a, long long b, long long c, long long d, long long e, long long f, long long g)
{
    long long sum1;
    long long sum2;
    long long sum_total;
    int result;

    //@ assert a >= -1000000000 && a <= 1000000000;
    //@ assert b >= -1000000000 && b <= 1000000000;
    //@ assert c >= -1000000000 && c <= 1000000000;
    //@ assert d >= -1000000000 && d <= 1000000000;
    //@ assert e >= -1000000000 && e <= 1000000000;
    //@ assert f >= -1000000000 && f <= 1000000000;

    //@ assert sum123(a,b,c) >= -3000000000 && sum123(a,b,c) <= 3000000000;
    sum1 = a + b + c;

    //@ assert sum456(d,e,f) >= -3000000000 && sum456(d,e,f) <= 3000000000;
    sum2 = d + e + f;

    //@ assert total_sum(a,b,c,d,e,f) >= -6000000000 && total_sum(a,b,c,d,e,f) <= 6000000000;
    sum_total = sum1 + sum2;

    result = (sum_total == g);
    return result;
}
