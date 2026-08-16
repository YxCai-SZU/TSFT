#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == ((a + b) / 2 >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    unsigned int average;
    unsigned int temp_sum;
    unsigned int count;

    sum = a + b;
    average = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
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

    //@ assert average == sum / 2;
    return average >= c;
}
