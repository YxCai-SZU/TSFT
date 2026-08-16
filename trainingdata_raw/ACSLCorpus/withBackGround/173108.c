#include <stdbool.h>

/*@
    predicate element_equal_to_itself(int* arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[i] == arr[i];

    predicate is_one_of(int val, int* arr, integer len) =
        \exists integer i; 0 <= i < len && val == arr[i];

    predicate is_maximum(int val, int* arr, integer len) =
        \forall integer i; 0 <= i < len ==> val >= arr[i];

    lemma max_property: \forall int* arr, integer len, int val;
        is_one_of(val, arr, len) && is_maximum(val, arr, len) ==>
            \exists integer i; 0 <= i < len && val == arr[i] &&
            \forall integer j; 0 <= j < len ==> val >= arr[j];
*/

/*@
    requires \valid(arr + (0..2));
    requires element_equal_to_itself(arr, 3);
    ensures is_one_of(\result, arr, 3);
    ensures is_maximum(\result, arr, 3);
    assigns \nothing;
*/
int find_peak(int arr[3]) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant is_one_of(max, arr, 3);
        loop invariant \forall integer j; 0 <= j < i ==> max >= arr[j];
        loop invariant element_equal_to_itself(arr, 3);
        loop assigns max, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert element_equal_to_itself(arr, 3);
        
        if (arr[i] > max) {
            max = arr[i];
        }
        
        //@ assert is_one_of(max, arr, 3);
        //@ assert \forall integer j; 0 <= j < i+1 ==> max >= arr[j];
        
        i = i + 1;
    }
    
    //@ assert is_maximum(max, arr, 3);
    return max;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
