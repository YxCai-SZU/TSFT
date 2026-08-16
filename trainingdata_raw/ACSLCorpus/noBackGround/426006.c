#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 10000);
    ensures \result == ((N * 2 + 1) / 2 > N);
*/
bool func(int N)
{
    bool result = false;
    int temp = 0;
    int count = 0;

    //@ assert (1 <= (N) && (N) <= 10000);
    temp = N * 2 + 1;
    count = 0;

    /*@
        loop invariant (1 <= (N) && (N) <= 10000);
        loop invariant temp >= 0;
        loop invariant temp == ((N) * 2 + 1 - 2 * (count));
        loop invariant 0 <= count && count <= (N * 2 + 1) / 2;
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }

    //@ assert temp == ((N) * 2 + 1 - 2 * (count));
    if (count > N)
    {
        result = true;
    }

    return result;
}
