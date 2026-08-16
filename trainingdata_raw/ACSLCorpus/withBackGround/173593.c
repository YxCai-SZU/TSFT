/*@
    predicate is_mod_10(integer n, integer m) =
        m == n % 10;

    predicate is_div_10_mod_10(integer n, integer m) =
        m == (n / 10) % 10;

    logic integer mod_10(integer n) = n % 10;
    logic integer div_10_mod_10(integer n) = (n / 10) % 10;

    lemma mod_10_lemma:
        \forall integer n; 10 <= n <= 99 ==>
        mod_10(n) == n - (n / 10) * 10;

    lemma div_10_mod_10_lemma:
        \forall integer n; 10 <= n <= 99 ==>
        div_10_mod_10(n) == (n / 10) - ((n / 10) / 10) * 10;
*/

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
*/
int func(unsigned int n)
{
    unsigned int n_mod_10;
    unsigned int n_div_10;
    unsigned int n_div_10_mod_10;
    int result;

    n_mod_10 = n - (n / 10) * 10;
    n_div_10 = n / 10;
    n_div_10_mod_10 = n_div_10 - (n_div_10 / 10) * 10;

    //@ assert n_mod_10 == n % 10;
    //@ assert n_div_10_mod_10 == (n / 10) % 10;

    result = (n_mod_10 == 9 || n_div_10_mod_10 == 9);
    return result;
}
