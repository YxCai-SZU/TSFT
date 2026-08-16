/*@
    predicate valid_inputs(integer n, integer m) =
        1 <= n && n <= 1000000000000 &&
        1 <= m && m <= 1000000000000;

    logic integer func_spec(integer n, integer m) =
        n > m / 2 ? m / 2 : n + (m - 2 * n) / 4;

    lemma func_bound: \forall integer n, m;
        valid_inputs(n, m) ==> 0 <= func_spec(n, m) && func_spec(n, m) <= n + m / 2;
*/

/*@
    requires valid_inputs(n, m);
    ensures \result == func_spec(n, m);
    ensures \result >= 0;
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    // Variable declarations at top of scope
    unsigned long long rem;
    unsigned long long add;
    unsigned long long result;

    if (n > m / 2)
    {
        result = m / 2;
        //@ assert result == func_spec(n, m);
        return result;
    }

    rem = m - 2 * n;
    add = rem / 4;
    result = n + add;
    
    //@ assert result == func_spec(n, m);
    return result;
}
