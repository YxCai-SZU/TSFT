#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (n == 7 || n == 5 || n == 3);
    assigns \nothing;
 */
bool func(int n)
{
    int answers[3];
    int i;
    bool result;

    answers[0] = 7;
    answers[1] = 5;
    answers[2] = 3;

    i = 0;
    result = false;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant 1 <= n <= 100;
        loop invariant \forall integer k; 0 <= k < i ==> answers[k] != n;
        loop invariant result == false || (result == true && \exists integer k; 0 <= k < i && answers[k] == n);
        loop assigns i, result;
        loop variant 3 - i;
     */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (answers[i] == n)
        {
            result = true;
            break;
        }
        i = i + 1;
    }

    //@ assert result == (n == 7 || n == 5 || n == 3);
    return result;
}
