/*@
    predicate is_valid_range(integer n) =
        1 <= n && n <= 10000;

    logic integer division_by_3(integer n) =
        n / 3;

    lemma division_property:
        \forall integer n, count, temp;
            is_valid_range(n) ==>
            temp == n - 3 * count ==>
            count >= 0 ==>
            count <= division_by_3(n) ==>
            temp >= 0 ==>
            temp < 3 ==>
            count == division_by_3(n);
*/

/*@
    requires is_valid_range(n);
    ensures \result == division_by_3(n);
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
        loop invariant 0 <= temp;
        loop invariant temp == n - 3 * count;
        loop invariant 0 <= count;
        loop invariant count <= division_by_3(n);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp = temp - 3;
        count = count + 1;
    }

    result = count;

    //@ assert result == division_by_3(n);

    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
