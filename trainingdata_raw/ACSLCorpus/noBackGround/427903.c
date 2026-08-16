#include <stdbool.h>

/*@
    requires 0 <= a <= 23 && 0 <= b <= 23;
    requires a >= 0 && b >= 0;
    ensures ((\result) == ((a) + (b)) % 24 && (\result) >= 0);
    assigns \nothing;
 */
int func(int a, int b)
{
    int sum;
    int result;

    sum = a + b;
    result = sum;

    /*@
        loop invariant 0 <= result <= sum;
        loop invariant result >= 0;
        loop invariant result == sum - 24 * ((sum - result) / 24);
        loop assigns result;
        loop variant result;
     */
    while (result >= 24)
    {
        //@ assert result >= 24;
        result -= 24;
    }

    //@ assert result == (a + b) % 24;
    //@ assert result >= 0;
    return result;
}

int main()
{
    return 0;
}
