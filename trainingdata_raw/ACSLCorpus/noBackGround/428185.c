#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(arr + (0..len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> arr[i] <= 4294967295;
  ensures \forall integer i; 0 <= i < len ==> \result <= arr[i];
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
*/
unsigned int min(const unsigned int* arr, size_t len) {
    unsigned int min_val;
    size_t i;
    
    min_val = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> min_val <= arr[j];
      loop invariant \exists integer j; 0 <= j < i && min_val == arr[j];
      loop assigns min_val, i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i++;
    }
    
    return min_val;
}

/*@
  requires \valid(arr + (0..len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> arr[i] <= 4294967295;
  ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
*/
unsigned int max(const unsigned int* arr, size_t len) {
    unsigned int max_val;
    size_t i;
    
    max_val = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> max_val >= arr[j];
      loop invariant \exists integer j; 0 <= j < i && max_val == arr[j];
      loop assigns max_val, i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i++;
    }
    
    return max_val;
}

/*@
  requires n < 0x80000000;
  ensures \result == (n % 2 != 0);
*/
bool is_odd_c(unsigned int n) {
    bool ret;
    ret = (n % 2 != 0);
    //@ assert ret == (n % 2 != 0);
    return ret;
}
