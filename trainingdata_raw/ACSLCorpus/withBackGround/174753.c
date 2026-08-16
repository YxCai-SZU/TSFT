/*@
    predicate is_divisible(integer n, integer m) = n % m == 0;
    predicate is_not_divisible(integer n, integer m) = n % m != 0;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> is_divisible(n, m);
    ensures \result == 1 ==> is_not_divisible(n, m);
*/
int func(unsigned int n, unsigned int m)
{
    unsigned int num;
    int ans;

    num = n % m;
    //@ assert num == n % m;

    if (num == 0)
    {
        ans = 0;
        //@ assert ans == 0;
        //@ assert is_divisible(n, m);
    }
    else
    {
        ans = 1;
        //@ assert ans == 1;
        //@ assert is_not_divisible(n, m);
    }

    return ans;
}
