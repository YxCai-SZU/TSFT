/*@
    predicate is_valid_n(integer n) = 0 <= n && n <= 1;

    logic integer func_res(integer n) = n == 1 ? 0 : 1;

    lemma func_ensures:
        \forall integer n;
        is_valid_n(n) ==> func_res(n) == (n == 1 ? 0 : 1);
*/

/*@
    requires is_valid_n(n);
    ensures \result == func_res(n);
    ensures (n == 1 ==> \result == 0) && (n == 0 ==> \result == 1);
*/
int func(int n)
{
    int ans;

    if (n == 1)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = 1;
        //@ assert ans == 1;
    }

    return ans;
}
