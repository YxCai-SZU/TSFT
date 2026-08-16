/*@
    predicate is_within_bounds(integer n, integer m) =
        1 <= n && n <= 100 && 1 <= m && m <= 100;

    lemma commutativity:
        \forall integer z, w; z + w == w + z;
*/

/*@
    requires is_within_bounds(n, m);
    ensures \result == n * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert 1 <= n * m && n * m <= 100 * 100;
    return n * m;
}

int main()
{
    return 0;
}
