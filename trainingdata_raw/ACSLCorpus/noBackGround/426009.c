#include <stdbool.h>
#include <stdint.h>

/*@
    requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> (numbers[i] > 0 && numbers[i] <= 1000000000);
    ensures \result == true <==> \forall integer i; 0 <= i < n ==> (numbers[i] % 2 == 0);
    assigns \nothing;
 */
bool func(uint32_t n, uint32_t *numbers)
{
    bool flag = true;
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true <==> (\forall integer j; (0) <= j < (i) ==> ((numbers)[j] % 2 == 0));
        loop assigns i, flag;
        loop variant n - i;
     */
    while (i < n)
    {
        uint32_t a = numbers[i];
        if (a % 2 != 0)
        {
            flag = false;
        }
        i = i + 1;
    }
    return flag;
}
