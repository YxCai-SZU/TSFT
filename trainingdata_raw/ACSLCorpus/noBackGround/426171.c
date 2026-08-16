#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= N <= 100;
    requires 1 <= i <= N;
    ensures \result == ((N) - ((i) - 1));
*/
int func(int N, int i) {
    int answer;
    //@ ghost int original_N = N;
    //@ ghost int original_i = i;
    
    answer = N - (i - 1);
    
    //@ assert answer == ((original_N) - ((original_i) - 1));
    return answer;
}

/*@ requires \valid_read(arr + (0..len-1));
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> ((arr)[i] % 2 == 0));
*/
bool is_even(const int *arr, size_t len) {
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant (\forall integer i; 0 <= i < (index) ==> ((arr)[i] % 2 == 0));
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len;
        if (arr[index] % 2 != 0) {
            //@ assert !(\forall integer i; 0 <= i < (len) ==> ((arr)[i] % 2 == 0));
            return false;
        }
        //@ assert arr[index] % 2 == 0;
        index++;
        //@ assert (\forall integer i; 0 <= i < (index) ==> ((arr)[i] % 2 == 0));
    }
    //@ assert index == len;
    //@ assert (\forall integer i; 0 <= i < (len) ==> ((arr)[i] % 2 == 0));
    return true;
}
