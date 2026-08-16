/*@
    predicate condition_holds(integer n, integer a, integer b) =
        (n - a >= 2 && a - 1 >= 1 && b - a >= 1 && n - b >= 1) ||
        (a == 1 && b == n);
 */

/*@
    requires 2 <= n && n <= 100;
    requires 1 <= a && a < b && b <= n;
    ensures \result == 1 <==> condition_holds(n, a, b);
 */
int func(int n, int a, int b)
{
    // Variable declarations at the top of the scope
    int result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 1 <= a && a < b && b <= n;

    if ((n - a >= 2 && a - 1 >= 1 && b - a >= 1 && n - b >= 1) ||
        (a == 1 && b == n))
    {
        result = 1;
        //@ assert condition_holds(n, a, b);
    }
    else
    {
        //@ assert !condition_holds(n, a, b);
        result = 0;
    }

    //@ assert result == 1 <==> condition_holds(n, a, b);
    return result;
}
