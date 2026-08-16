#include <stdbool.h>
#include <limits.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  requires (\forall integer j; 0 <= j < (len) ==> (((arr)[j]) >= INT_MIN && ((arr)[j]) <= INT_MAX));
  assigns \nothing;
  ensures \exists integer i; (0 <= (i) && (i) < (len)) && \result == arr[i];
  ensures (\forall integer j; 0 <= j < (len) ==> (\result) >= (arr)[j]);
*/
int find_max(int *arr, int len) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant (\forall integer j; 0 <= j < (len) ==> (((arr)[j]) >= INT_MIN && ((arr)[j]) <= INT_MAX));
      loop invariant \exists integer j; (0 <= (j) && (j) < (i)) && max == arr[j];
      loop invariant \forall integer k; 0 <= k < i ==> max >= arr[k];
      loop assigns max, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert (0 <= (i) && (i) < (len));
        //@ assert ((arr[i]) >= INT_MIN && (arr[i]) <= INT_MAX);
        
        if (arr[i] > max) {
            max = arr[i];
        }
        
        i = i + 1;
    }
    
    //@ assert (\forall integer j; 0 <= j < (len) ==> (max) >= (arr)[j]);
    return max;
}
