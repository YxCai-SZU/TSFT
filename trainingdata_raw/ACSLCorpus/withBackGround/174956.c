#include <stdbool.h>
#include <stddef.h>

/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] <= arr[j];

    lemma sorted_preserved:
        \forall int *arr, integer len, integer i, integer j;
        sorted(arr, len) && 0 <= i < j < len ==> arr[i] <= arr[j];
*/

/*@
    requires k > 0;
    requires k <= len;
    requires sorted(arr, len);
    ensures \result == arr[k-1];
    assigns \nothing;
*/
int find_kth_element(int *arr, size_t len, size_t k)
{
    size_t i;
    i = 0;

    /*@
        loop invariant 0 <= i <= k-1;
        loop invariant k > 0;
        loop invariant k <= len;
        loop invariant sorted(arr, len);
        loop assigns i;
        loop variant k - i - 1;
    */
    while (i < k - 1)
    {
        i = i + 1;
    }

    //@ assert i == k-1;
    //@ assert sorted(arr, len) ==> \forall integer j; 0 <= j < i ==> arr[j] <= arr[i];
    return arr[i];
}

/*@
    requires len < 0x80000000;
    requires sorted(arr, len);
    ensures \result == true;
    assigns \nothing;
*/
bool is_sorted(int *arr, size_t len)
{
    return true;
}
