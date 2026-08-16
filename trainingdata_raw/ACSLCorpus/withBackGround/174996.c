#include <stdbool.h>
#include <limits.h>

/*@
    predicate is_seq(int *arr, integer len) =
        len >= 0 && \valid(arr + (0 .. len-1));
*/

/*@
    axiomatic SeqMinMax {
        logic integer seq_min(int *arr, integer len) reads arr[0 .. len-1];
        
        axiom seq_min_empty: 
            \forall int *arr; seq_min(arr, 0) == INT_MAX;
        
        axiom seq_min_nonempty:
            \forall int *arr, integer len; len > 0 ==>
                (\forall integer i; 0 <= i < len ==> arr[i] >= seq_min(arr, len)) &&
                (\exists integer j; 0 <= j < len && arr[j] == seq_min(arr, len));

        logic integer seq_max(int *arr, integer len) reads arr[0 .. len-1];
        
        axiom seq_max_empty: 
            \forall int *arr; seq_max(arr, 0) == INT_MIN;
        
        axiom seq_max_nonempty:
            \forall int *arr, integer len; len > 0 ==>
                (\forall integer i; 0 <= i < len ==> arr[i] <= seq_max(arr, len)) &&
                (\exists integer j; 0 <= j < len && arr[j] == seq_max(arr, len));
    }
*/

/*@
    lemma min_ensures:
        \forall int *arr, integer len;
        is_seq(arr, len) && len == 5 &&
        arr[0] == 90 && arr[1] == 80 && arr[2] == 70 &&
        arr[3] == 60 && arr[4] == 50 ==>
        seq_min(arr, len) == 50;

    lemma max_ensures:
        \forall int *arr, integer len;
        is_seq(arr, len) && len == 5 &&
        arr[0] == 90 && arr[1] == 80 && arr[2] == 70 &&
        arr[3] == 60 && arr[4] == 50 ==>
        seq_max(arr, len) == 90;
*/

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 5;
    requires arr[0] == 90 && arr[1] == 80 && arr[2] == 70 &&
             arr[3] == 60 && arr[4] == 50;
    assigns \nothing;
    ensures \result == 50;
*/
int test_seq_min(int *arr, int len) {
    int min_val;
    int i;

    //@ assert is_seq(arr, len);
    
    //@ assert seq_min(arr, len) == 50;
    
    min_val = arr[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] >= min_val;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == min_val;
        loop assigns i, min_val;
    */
    while (i < len) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i++;
    }
    
    //@ assert seq_max(arr, len) == 90;
    
    return min_val;
}

/*@
    assigns \nothing;
*/
int main() {
    int arr[5] = {90, 80, 70, 60, 50};
    int result = test_seq_min(arr, 5);
    return 0;
}
