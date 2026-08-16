#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 == 1;
*/

/*@
    requires 1 <= a <= b <= 20;
    ensures \result == a + b || \result == b - a;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    bool is_even_flag;
    int temp_a;
    int temp_b;
    int sum;

    result = 0;
    is_even_flag = false;
    temp_a = a;
    temp_b = b;
    sum = temp_a + temp_b;

    /*@
        loop invariant 0 <= sum <= temp_a + temp_b;
        loop invariant sum % 2 == (temp_a + temp_b) % 2;
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= 2)
    {
        sum -= 2;
    }

    if (sum == 0)
    {
        is_even_flag = true;
    }

    if (is_even_flag)
    {
        result = a + b;
    }
    else
    {
        result = b - a;
    }

    //@ assert is_even_flag ==> result == a + b;
    //@ assert !is_even_flag ==> result == b - a;
    return result;
}

int main()
{
    return 0;
}
