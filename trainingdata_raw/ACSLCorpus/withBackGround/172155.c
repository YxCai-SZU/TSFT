/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;

    logic integer func_result(integer n) = n * (n - 1) / 2;

    lemma arithmetic_bounds:
        \forall integer n; is_valid_n(n) ==> n * (n - 1) <= 100 * 99;
*/

/*@
    requires is_valid_n(n);
    ensures \result == func_result(n);
    assigns \nothing;
*/
unsigned long func(unsigned long n)
{
    // Variable declarations at scope top
    unsigned long ans;

    //@ assert is_valid_n(n);
    //@ assert n > 0;
    //@ assert n <= 100;
    //@ assert n * (n - 1) <= 100 * 99;

    ans = n * (n - 1) / 2;
    //@ assert ans == func_result(n);
    
    return ans;
}
