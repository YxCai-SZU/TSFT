#include <stddef.h>
#include <limits.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires (\forall integer k; 0 <= k < (len) ==> INT_MIN <= (arr)[k] <= INT_MAX);
    ensures \result <= len;
    ensures (\forall integer k; 0 <= k < (len) && (arr)[k] == (num) ==> (\result) > 0);
    ensures (\forall integer k; 0 <= k < (len) && (arr)[k] != (num) ==> (\result) >= 0);
*/
size_t count_occurrences(int* arr, size_t len, int num) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant (\forall integer k; 0 <= k < (i) ==> INT_MIN <= (arr)[k] <= INT_MAX);
        loop invariant (\forall integer k; 0 <= k < (i) && (arr)[k] == (num) ==> (count) > 0);
        loop invariant (\forall integer k; 0 <= k < (i) && (arr)[k] != (num) ==> (count) >= 0);
        loop invariant (\forall integer k; 0 <= k < (len) ==> INT_MIN <= (arr)[k] <= INT_MAX);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer k; 0 <= k < (len) ==> INT_MIN <= (arr)[k] <= INT_MAX);
        if (arr[i] == num) {
            count++;
        }
        i++;
    }
    return count;
}
