#include <stddef.h>

/*@
    requires k > 0;
    requires k <= len;
    requires \valid(arr + (0 .. len-1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    ensures \result == arr[k-1];
    assigns \nothing;
*/
int find_kth_element(int *arr, size_t len, size_t k) {
    int result;
    
    //@ assert k-1 < len;
    result = arr[k-1];
    
    return result;
}
