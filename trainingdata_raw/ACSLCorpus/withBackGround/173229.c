/*@
    predicate is_valid_range(integer n) =
        1 <= n <= 1000000000;

    logic integer division_result(integer n) =
        n / 3;

    lemma division_property:
        \forall integer n; is_valid_range(n) ==> division_result(n) >= 0;
*/

/*@
    requires is_valid_range(n);
    ensures \result == division_result(n);
    assigns \nothing;
*/
long func(long n)
{
    long result;
    long temp;
    long count;

    result = 0;
    temp = n;
    count = 0;

    /*@
        loop invariant 1 <= n <= 1000000000;
        loop invariant 0 <= temp <= n;
        loop invariant temp == n - 3 * count;
        loop invariant 0 <= count <= n / 3;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
        count += 1;
    }

    result = count;
    //@ assert result == division_result(n);
    return result;
}

int main(void)
{
    return 0;
}
