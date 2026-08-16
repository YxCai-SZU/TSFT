#include <stdbool.h>

/*@
    predicate all_distinct(int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];

    predicate in_range(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 9;

    predicate sorted_three(int a, int b, int c) =
        a <= b && b <= c;

    predicate distinct_three(int a, int b, int c) =
        a != b && b != c && a != c;

    logic integer vector_len(int *arr) = 3;
*/

/*@
    requires \valid(v) && vector_len(v) >= 3;
    requires all_distinct(v, vector_len(v));
    requires in_range(v, vector_len(v));
    ensures 0 <= \result <= 9;
    ensures \result != v[0] || \result != v[1] || \result != v[2];
    assigns \nothing;
*/
int func(int *v)
{
    int v0;
    int v1;
    int v2;
    int result;
    int i;
    int temp;

    v0 = v[0];
    v1 = v[1];
    v2 = v[2];

    //@ assert v0 >= 1 && v0 <= 9;
    //@ assert v1 >= 1 && v1 <= 9;
    //@ assert v2 >= 1 && v2 <= 9;

    if (v0 > v1)
    {
        temp = v0;
        v0 = v1;
        v1 = temp;
    }
    if (v1 > v2)
    {
        temp = v1;
        v1 = v2;
        v2 = temp;
    }
    if (v0 > v1)
    {
        temp = v0;
        v0 = v1;
        v1 = temp;
    }

    //@ assert sorted_three(v0, v1, v2);
    //@ assert distinct_three(v0, v1, v2);

    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= 10;
        loop invariant 0 <= result <= 9;
        loop invariant result != v0 || result != v1 || result != v2;
        loop invariant sorted_three(v0, v1, v2);
        loop invariant distinct_three(v0, v1, v2);
        loop invariant v0 >= 1 && v0 <= 9;
        loop invariant v1 >= 1 && v1 <= 9;
        loop invariant v2 >= 1 && v2 <= 9;
        loop invariant i > 0 ==> result != v0 || result != v1 || result != v2;
        loop assigns i, result;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        int v_i_0;
        int v_i_1;
        int v_i_2;

        v_i_0 = (i == 0) ? v0 : v1;
        v_i_1 = (i == 1) ? v1 : v2;
        v_i_2 = (i == 2) ? v2 : v0;

        if (v_i_0 != i && v_i_1 != i && v_i_2 != i)
        {
            result = i;
            break;
        }
        i = i + 1;
    }

    //@ assert 0 <= result && result <= 9;
    return result;
}
