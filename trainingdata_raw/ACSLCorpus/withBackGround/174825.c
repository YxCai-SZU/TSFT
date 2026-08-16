/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer target_value(integer a, integer b) =
        (a + b + 1) / 2;

    lemma division_property:
        \forall integer a, b;
        is_valid_range(a, b) ==>
        target_value(a, b) == (a + b + 1) / 2;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a + b + 1) / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int temp;
    int count;

    sum = a + b;
    result = 0;
    temp = sum + 1;
    count = 0;

    /*@
        loop invariant sum == a + b;
        loop invariant temp == sum + 1 - 2 * count;
        loop invariant result == count;
        loop invariant temp >= 0;
        loop invariant count >= 0;
        loop assigns temp, result, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        result += 1;
        count += 1;
    }

    //@ assert result == (a + b + 1) / 2;

    return result;
}
