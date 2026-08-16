#include <stdbool.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 2;
    requires 1 <= len <= 100;
    requires \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 100;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < (arr)[i + 1]);
    assigns \nothing;
*/
bool is_increasing_sequence(int *arr, int len) {
    int i;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 1 <= i && i < len;
        
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
        i += 1;
    }
    return true;
}
