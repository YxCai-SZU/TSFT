#include <stddef.h>
#include <stdbool.h>

/*@ requires k > 0;
    requires k <= len;
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    requires \valid_read(arr + (0 .. len-1));
    ensures \result == arr[k-1];
    ensures len > 0;
*/
int find_kth_element(int *arr, size_t len, size_t k) {
    // Declare all variables at the top
    int result;

    // Check if k is within bounds
    if (k < 1 || k > len) {
        //@ assert k < 1 || k > len;
        return -1;
    }

    // Since we know k is within bounds, we can safely return the element
    //@ assert len > 0;
    //@ assert k > 0 && k <= len;
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);

    // Add assertion to ensure no underflow/overflow occurs
    //@ assert k - 1 < len;

    result = arr[k - 1];
    //@ assert result == arr[k-1];
    return result;
}
