#include <stdbool.h>
#include <limits.h>

/*@ requires \valid(list+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && list[i] == \result;
*/
int find_max(int *list, int len) {
    int max_val = INT_MIN;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant i == 0 ==> max_val == INT_MIN;
        loop invariant i > 0 ==> \exists integer k; 0 <= k < i && list[k] == max_val;
        loop invariant \forall integer j; 0 <= j < i ==> list[j] <= max_val;
        loop assigns max_val, i;
        loop variant len - i;
    */
    while (i < len) {
        int item = list[i];
        if (item > max_val) {
            max_val = item;
        }
        i++;
    }
    return max_val;
}
