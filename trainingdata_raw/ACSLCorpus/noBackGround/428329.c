#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    
    assigns \nothing;
    
    ensures \result == true ==> ((len) > 0 &&
        \forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] > (arr)[i + 1]);
    ensures \result == false ==> ((len) > 0 &&
        \exists integer i; 0 <= i < (len) - 1 && (arr)[i] <= (arr)[i + 1]);
*/
bool is_strictly_decreasing(int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] > arr[j + 1];
        loop assigns i;
        loop variant len - i - 1;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        
        if (arr[i] <= arr[i + 1]) {
            //@ assert \exists integer j; 0 <= j < len - 1 && arr[j] <= arr[j + 1];
            return false;
        }
        
        i++;
    }
    
    //@ assert \forall integer j; 0 <= j < len - 1 ==> arr[j] > arr[j + 1];
    return true;
}

int main() {
    return 0;
}
