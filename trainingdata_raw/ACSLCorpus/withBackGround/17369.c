/*@
    predicate valid_params(integer n, integer a, integer b) =
        2 <= n <= 100 &&
        1 <= a <= n - 1 &&
        1 <= b <= n - 1;

    logic integer mod2(integer x) = x % 2;

    lemma mod2_property:
        \forall integer sum, temp_sum;
        (sum - temp_sum) % 2 == 0 && temp_sum % 2 == sum % 2 ==>
        mod2(sum) == mod2(temp_sum);
*/

#include <stdbool.h>

/*@
    requires valid_params(n, a, b);
    ensures \result == true <==> (a + b) % 2 == 0;
*/
bool func(int n, int a, int b)
{
    int sum;
    bool is_even;
    int temp_sum;

    //@ assert valid_params(n, a, b);
    sum = a + b;
    is_even = true;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= a + b;
        loop invariant 2 <= n <= 100;
        loop invariant 1 <= a <= n - 1;
        loop invariant 1 <= b <= n - 1;
        loop invariant temp_sum <= sum;
        loop invariant (sum - temp_sum) % 2 == 0;
        loop invariant temp_sum % 2 == sum % 2;
        loop assigns temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
    }

    //@ assert temp_sum % 2 == sum % 2;
    if (temp_sum == 1) {
        is_even = false;
    }

    //@ assert is_even == true <==> sum % 2 == 0;
    return is_even;
}
