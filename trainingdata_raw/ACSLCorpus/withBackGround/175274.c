/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer expected_result(integer a, integer b) =
        (a + b + 1) / 2;

    lemma sum_bound: \forall integer a, b; valid_range(a, b) ==> a + b <= 200;
*/

/*@
    requires valid_range(a, b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int average;
    int temp_sum;
    int count;

    sum = a + b;
    average = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == a + b;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    average = count;

    if (sum > 0 && temp_sum > 0)
    {
        average += 1;
    }

    //@ assert average == expected_result(a, b);
    return average;
}

/*@
    requires valid_range(a, b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int main2(int a, int b)
{
    int sum;
    int average;
    int temp_sum;
    int count;

    sum = a + b;
    average = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == a + b;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant valid_range(a, b);
        loop invariant sum <= 200;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    average = count;

    if (sum > 0 && temp_sum > 0)
    {
        average += 1;
    }

    //@ assert average == expected_result(a, b);
    return average;
}

int main()
{
    return 0;
}
