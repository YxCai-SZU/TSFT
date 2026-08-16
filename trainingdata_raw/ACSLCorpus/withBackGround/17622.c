#include <stdbool.h>

/*@
    predicate sorted(integer min, integer mid, integer max) =
        min <= mid && mid <= max;

    predicate within_range(integer min, integer max) =
        max - min <= 99;

    logic integer answer(integer min, integer max) =
        max - min == 2 ? 3 :
        max - min == 1 ? 2 : 1;

    lemma answer_range:
        \forall integer min, max;
        within_range(min, max) ==>
        answer(min, max) >= 1 && answer(min, max) <= 3;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1;
    ensures \result <= 3;
*/
int func(int a, int b, int c)
{
    int min;
    int mid;
    int max;
    int temp;
    int ans;

    min = a;
    mid = b;
    max = c;

    //@ assert 1 <= min <= 100;
    //@ assert 1 <= mid <= 100;
    //@ assert 1 <= max <= 100;

    if (min > mid)
    {
        temp = min;
        min = mid;
        mid = temp;
    }

    //@ assert min <= mid;

    if (mid > max)
    {
        temp = mid;
        mid = max;
        max = temp;
    }

    //@ assert mid <= max;

    if (min > mid)
    {
        temp = min;
        min = mid;
        mid = temp;
    }

    //@ assert sorted(min, mid, max);
    //@ assert within_range(min, max);

    if (max - min == 2)
    {
        ans = 3;
    }
    else if (max - min == 1)
    {
        ans = 2;
    }
    else
    {
        ans = 1;
    }

    //@ assert ans == answer(min, max);
    //@ assert ans >= 1 && ans <= 3;

    return ans;
}
