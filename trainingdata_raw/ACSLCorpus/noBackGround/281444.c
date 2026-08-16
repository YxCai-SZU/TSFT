#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 1 && (len) <= 100);
    requires (\forall integer i; 0 <= i < (len) ==> 
            ((arr)[i] == 9 || (arr)[i] != 9));
    
    ensures \result == true ==> 
        \exists integer i; 0 <= i < len && arr[i] == 9;
    ensures \result == false ==> 
        \forall integer i; 0 <= i < len ==> arr[i] != 9;
*/
bool contains_nine(int *arr, size_t len) {
    size_t i = 0;
    
    //@ ghost int *original_arr = arr;
    //@ ghost size_t original_len = len;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant ((original_len) >= 1 && (original_len) <= 100);
        loop invariant (\forall integer i; 0 <= i < (original_len) ==> 
            ((original_arr)[i] == 9 || (original_arr)[i] != 9));
        loop invariant (\forall integer j; 0 <= j < (i) ==> (original_arr)[j] != 9);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        
        if (arr[i] == 9) {
            //@ assert \exists integer j; 0 <= j < len && arr[j] == 9;
            return true;
        }
        
        //@ assert arr[i] != 9;
        i++;
    }
    
    //@ assert \forall integer k; 0 <= k < len ==> arr[k] != 9;
    return false;
}

int main() {
    return 0;
}
