/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer expected_result(integer n) = (n + 1) / 2;

    lemma result_nonnegative: \forall integer n; valid_n(n) ==> expected_result(n) >= 0;
    lemma result_range: \forall integer n; valid_n(n) ==> expected_result(n) >= 0 && expected_result(n) <= 50;
*/

/*@
    requires valid_n(n);
    ensures \result >= 0;
    ensures \result == expected_result(n);
*/
int func(unsigned int n)
{
    int result;
    //@ assert n >= 1 && n <= 100;
    //@ assert n + 1 >= 0 && n + 1 <= 101;
    
    if (n % 2 == 0) {
        result = (int)(n / 2);
    } else {
        result = (int)(n / 2 + 1);
    }
    
    //@ assert result == (int)((n + 1) / 2);
    return result;
}
