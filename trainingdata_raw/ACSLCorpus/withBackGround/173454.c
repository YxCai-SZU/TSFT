/*@
    predicate is_one(integer n) = n == 1;
    predicate is_zero(integer n) = n == 0;
*/

/*@
    requires 0 <= n <= 1;
    ensures is_one(n) ==> \result == 0;
    ensures is_zero(n) ==> \result == 1;
*/
int func(int n)
{
    int res;

    if (n == 1) {
        //@ assert is_one(n);
        res = 0;
    } else {
        //@ assert is_zero(n);
        res = 1;
    }

    return res;
}
