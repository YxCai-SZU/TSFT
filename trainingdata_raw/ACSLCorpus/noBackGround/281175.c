#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == ((((n)) / (3)) + (((n)) / (9)) + (((n)) / (27)) + (((n)) / (81))) || \result == ((((n)) / (3)) + (((n)) / (9)) + (((n)) / (27)) + (((n)) / (81))) + 1;
*/
int func(int n)
{
    int count;
    int temp_n;
    int quotient_3;
    int quotient_9;
    int quotient_27;
    int quotient_81;
    
    count = 0;
    
    // Manual division by 3
    quotient_3 = 0;
    temp_n = n;
    /*@
        loop invariant 0 <= quotient_3 <= n / 3;
        loop invariant temp_n == n - 3 * quotient_3;
        loop invariant 1 <= n <= 10000;
        loop assigns quotient_3, temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
        quotient_3 += 1;
    }
    count += quotient_3;
    
    // Manual division by 9
    quotient_9 = 0;
    temp_n = n;
    /*@
        loop invariant 0 <= quotient_9 <= n / 9;
        loop invariant temp_n == n - 9 * quotient_9;
        loop invariant 1 <= n <= 10000;
        loop assigns quotient_9, temp_n;
    */
    while (temp_n >= 9)
    {
        temp_n -= 9;
        quotient_9 += 1;
    }
    count += quotient_9;
    
    // Manual division by 27
    quotient_27 = 0;
    temp_n = n;
    /*@
        loop invariant 0 <= quotient_27 <= n / 27;
        loop invariant temp_n == n - 27 * quotient_27;
        loop invariant 1 <= n <= 10000;
        loop assigns quotient_27, temp_n;
    */
    while (temp_n >= 27)
    {
        temp_n -= 27;
        quotient_27 += 1;
    }
    count += quotient_27;
    
    // Manual division by 81
    quotient_81 = 0;
    temp_n = n;
    /*@
        loop invariant 0 <= quotient_81 <= n / 81;
        loop invariant temp_n == n - 81 * quotient_81;
        loop invariant 1 <= n <= 10000;
        loop assigns quotient_81, temp_n;
    */
    while (temp_n >= 81)
    {
        temp_n -= 81;
        quotient_81 += 1;
    }
    count += quotient_81;
    
    return count;
}
