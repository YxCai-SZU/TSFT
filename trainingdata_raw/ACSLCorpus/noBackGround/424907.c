#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
    requires len < 0x80000000;
    ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (x));
    ensures \result == false <==> !(\exists integer i; 0 <= i < (len) && (arr)[i] == (x));
    assigns \nothing;
*/
bool contains_value(int *arr, size_t len, int x)
{
    size_t low = 0;
    size_t high = len;

    /*@
        loop invariant 0 <= low <= high <= len;
        loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
        loop invariant \forall integer k; 0 <= k < low ==> arr[k] < x;
        loop invariant \forall integer k; high <= k < len ==> arr[k] > x;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high)
    {
        size_t mid = low + (high - low) / 2;

        //@ assert low <= mid < high;
        if (arr[mid] < x)
        {
            //@ assert \forall integer k; 0 <= k <= mid ==> arr[k] < x;
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            //@ assert \forall integer k; mid <= k < len ==> arr[k] > x;
            high = mid;
        }
        else
        {
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (x));
            return true;
        }
    }

    //@ assert !(\exists integer i; 0 <= i < (len) && (arr)[i] == (x));
    return false;
}
