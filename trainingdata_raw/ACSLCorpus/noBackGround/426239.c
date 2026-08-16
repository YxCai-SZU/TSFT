#include <stdbool.h>
#include <stddef.h>

/*@
    requires len >= 1;
    requires arr[0] > 0;
    ensures \result >= arr[0];
    ensures \forall integer i; 0 <= i < len ==> arr[i] <= \result;
*/
unsigned int func(unsigned int *arr, size_t len) {
    unsigned int max_value;
    size_t i;
    
    max_value = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant arr[0] > 0;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max_value;
        loop assigns max_value, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert arr[i] <= max_value || arr[i] > max_value;
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        i++;
    }
    
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] <= max_value;
    return max_value;
}

int main() {
    return 0;
}
