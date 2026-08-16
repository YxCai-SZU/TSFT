#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
*/
int func(int a, int b)
{
    int sum;
    int result;
    int i;
    int count;

    sum = a + b + 1;
    result = 0;
    i = 0;
    count = sum;

    /*@
        loop invariant 0 <= i;
        loop invariant 0 <= count <= sum;
        loop invariant sum == a + b + 1;
        loop invariant result == i;
        loop invariant count == sum - 2 * i;
        loop invariant i <= sum / 2;
        loop assigns result, count, i;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        result += 1;
        count -= 2;
        i += 1;
    }

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
