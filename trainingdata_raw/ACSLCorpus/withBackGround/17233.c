#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_index(int* arr, integer len, integer k) =
        k > 0 && k <= len;
    
    logic integer kth_element_logic(int* arr, integer len, integer k) =
        arr[k-1];
*/

/*@
    requires \valid(arr + (0..len-1));
    requires valid_index(arr, len, k);
    ensures \result == kth_element_logic(arr, len, k);
*/
int kth_element(int* arr, size_t len, size_t k) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert valid_index(arr, len, k);
    
    result = arr[k - 1];
    
    //@ assert result == kth_element_logic(arr, len, k);
    return result;
}

/*@
    lemma kth_element_correct: 
        \forall int* arr, integer len, integer k; 
        valid_index(arr, len, k) ==> 
        kth_element_logic(arr, len, k) == arr[k-1];
*/
