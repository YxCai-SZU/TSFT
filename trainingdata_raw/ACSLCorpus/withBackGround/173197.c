/*@
    predicate is_valid_params(integer n, integer a) =
        1 <= n && n <= 100 &&
        0 <= a && a <= n * n;

    lemma n_squared_bounded: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires is_valid_params(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int a)
{
    // Variable declarations at scope top
    unsigned int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 10000;

    result = n * n - a;
    return result;
}

int main(void)
{
    // Main function to satisfy compiler
    return 0;
}
