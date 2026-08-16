#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * ((a) + 1)) / 2;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t sum_of_natural_numbers;
    int64_t result;
    int64_t count;
    int64_t temp_sum;

    //@ assert (1 <= (a) <= 100);
    //@ assert 0 <= ((a) * ((a) + 1)) <= 10100;

    sum_of_natural_numbers = a * (a + 1);
    result = 0;
    count = 0;
    temp_sum = sum_of_natural_numbers;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= count <= sum_of_natural_numbers / 2;
        loop invariant temp_sum == sum_of_natural_numbers - 2 * count;
        loop invariant sum_of_natural_numbers == a * (a + 1);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    result = count;

    //@ assert result * 2 == a * (a + 1);
    return result;
}

int main()
{
    return 0;
}
