/*@
    predicate is_min(integer a, integer b, integer m) =
        m == a || m == b;

    lemma min_lemma: \forall integer a, b, m; is_min(a, b, m) ==> (m == a || m == b);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= x <= 200;
    ensures \result == (x <= a + b && a <= x);
*/
int func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long min;

    if (a < b) {
        min = a;
    } else {
        min = b;
    }

    //@ assert is_min(a, b, min);

    return x <= a + b && a <= x;
}
