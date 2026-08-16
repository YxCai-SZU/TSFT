/*@
    predicate is_valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    predicate ensures_result(integer n, integer m, integer result) =
        result >= 1 &&
        (m < n ==> result == 1) &&
        (m >= n ==> result == n + m - m);
*/

/*@
    requires is_valid_range(n, m);
    ensures ensures_result(n, m, \result);
*/
int func(int n, int m)
{
    int result;
    //@ assert is_valid_range(n, m);
    
    if (m < n)
    {
        result = 1;
    }
    else
    {
        //@ assert m >= n;
        result = n + m - m;
    }
    
    //@ assert ensures_result(n, m, result);
    return result;
}
