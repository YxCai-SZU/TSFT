#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n && n <= 100000;
    requires 1 <= m && m <= 100000;
    requires \valid(arr + (0..n-1));
    requires \valid(arr1 + (0..m-1));
    ensures 0 <= \result && \result <= m;
    assigns \nothing;
*/
int func(int n, int m, int *arr, int *arr1) {
    int count = 0;
    size_t index = 0;
    
    /*@
        loop invariant (0 <= (index) && (index) <= (m) &&
        0 <= (count) && (count) <= (index) &&
        (1 <= ((n)) && ((n)) <= 100000 &&
        1 <= ((m)) && ((m)) <= 100000));
        loop assigns index, count;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        int target = arr1[index];
        bool found = false;
        size_t j = 0;
        
        /*@
            loop invariant (0 <= (j) && (j) <= (n) &&
        0 <= (count) && (count) <= (index) &&
        (1 <= ((n)) && ((n)) <= 100000 &&
        1 <= ((m)) && ((m)) <= 100000));
            loop assigns j, found;
            loop variant n - j;
        */
        while (j < (size_t)n) {
            if (arr[j] == target) {
                found = true;
                break;
            }
            j++;
        }
        
        if (found) {
            count++;
        }
        index++;
    }
    
    //@ assert 0 <= count && count <= m;
    return count;
}
