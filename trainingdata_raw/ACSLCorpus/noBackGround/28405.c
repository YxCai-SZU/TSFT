#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  assigns \nothing;
  ensures 0 <= \result <= len;
  ensures \forall integer i; 0 <= i < len ==> arr[i] == arr[i];
*/
size_t count_occurrences(const int *arr, size_t len, int num) {
    size_t i = 0;
    size_t count = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] != num ==> arr[j] != num;
      loop invariant \forall integer k; 0 <= k < len ==> arr[k] == arr[k];
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] == num) {
            count++;
        }
        i++;
        //@ assert \forall integer j; 0 <= j < i ==> arr[j] != num ==> arr[j] != num;
    }
    return count;
}

int main() {
    return 0;
}
