/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;

    logic integer division_by_subtraction(integer n, integer count) = n - 2 * count;

    lemma division_property:
        \forall integer n, count;
        is_valid_range(n) && 0 <= count <= n/2 && 0 <= division_by_subtraction(n, count) <= n ==>
        division_by_subtraction(n, count) == n - 2 * count;
*/

/*@
    requires is_valid_range(n);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    int count = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 2;
        loop invariant temp_n == n - 2 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }

    int remainder = (temp_n == 1) ? 1 : 0;
    result = count + remainder;

    //@ assert result == n / 2 + n % 2;
    return result;
}
