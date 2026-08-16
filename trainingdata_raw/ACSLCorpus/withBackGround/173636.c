#include <stdbool.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len >= 1 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;

    predicate max_in_range(int* arr, integer len, integer idx, int max_val) =
        0 <= idx < len && arr[idx] == max_val;

    predicate min_in_range(int* arr, integer len, integer idx, int min_val) =
        0 <= idx < len && arr[idx] == min_val;

    lemma max_min_difference_bound:
        \forall int max_val, min_val;
        1 <= min_val <= max_val <= 100 ==> max_val - min_val <= 99;
*/

/*@
    requires \valid(numbers + (0..len-1));
    requires valid_range(numbers, len);
    ensures \result >= 0;
    ensures \exists integer max_idx, min_idx;
        0 <= max_idx < len && 0 <= min_idx < len &&
        numbers[max_idx] - numbers[min_idx] == \result;
*/
int func(int* numbers, int len) {
    int max_num;
    int min_num;
    int i;
    
    max_num = numbers[0];
    min_num = numbers[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant valid_range(numbers, len);
        loop invariant \forall integer k; 0 <= k < i ==> max_num >= numbers[k];
        loop invariant \forall integer k; 0 <= k < i ==> min_num <= numbers[k];
        loop invariant 1 <= max_num <= 100;
        loop invariant 1 <= min_num <= 100;
        loop invariant \exists integer max_idx; 0 <= max_idx < i && max_num == numbers[max_idx];
        loop invariant \exists integer min_idx; 0 <= min_idx < i && min_num == numbers[min_idx];
        loop invariant max_num - min_num <= 99;
        loop assigns max_num, min_num, i;
    */
    while (i < len) {
        int num = numbers[i];
        
        if (num > max_num) {
            max_num = num;
        }
        if (num < min_num) {
            min_num = num;
        }
        i++;
    }
    
    //@ assert max_num - min_num >= 0;
    return max_num - min_num;
}
