/*@
    predicate bounds(integer n) = -100 <= n && n <= 100;
    logic integer square(integer n) = n * n;
    logic integer cube_val(integer n) = n * n * n;
    lemma square_bounds: \forall integer n; bounds(n) ==> -10000 <= square(n) && square(n) <= 10000;
    lemma cube_bounds: \forall integer n; bounds(n) ==> -1000000 <= cube_val(n) && cube_val(n) <= 1000000;
*/

/*@
    requires -100 <= n && n <= 100;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int cube(int n)
{
    //@ assert -100 <= n && n <= 100;
    //@ assert -10000 <= n * n && n * n <= 10000;
    //@ assert -1000000 <= n * n * n && n * n * n <= 1000000;
    return n * n * n;
}

int main()
{
    return 0;
}
