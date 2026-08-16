/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer scaled_sum(integer a, integer b) = a * 100 + b * 100;
*/

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    ensures \result == 1 <==> is_even(scaled_sum(A, B));
    assigns \nothing;
*/
int func(int A, int B) {
    int scaled_a;
    int scaled_b;
    int sum;
    int result;
    int temp_sum;

    scaled_a = A * 100;
    scaled_b = B * 100;
    sum = scaled_a + scaled_b;
    result = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 2 == sum % 2;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
    }

    if (temp_sum == 0) {
        result = 1;
    }

    return result;
}
