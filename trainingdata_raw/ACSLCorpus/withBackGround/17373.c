#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 1 <= n && n <= 100; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer j; 0 <= j < n ==> 0 <= arr[j] && arr[j] <= 1000; */
/*@ predicate max_ge_all(int max, int *arr, integer i) = 
      \forall integer j; 0 <= j < i ==> max >= arr[j]; */
/*@ predicate min_le_all(int min, int *arr, integer i) = 
      \forall integer j; 0 <= j < i ==> min <= arr[j]; */

/*@ lemma max_min_relation: 
      \forall int max, int min; max >= min ==> max - min >= 0; */

/*@ requires valid_range(n);
    requires \valid(input_numbers + (0 .. n-1));
    requires valid_array(input_numbers, n);
    ensures \result >= 0;
*/
int func(size_t n, int input_numbers[]) {
    int max_num;
    int min_num;
    size_t i;
    
    //@ assert n >= 1 && n <= 100;
    max_num = input_numbers[0];
    min_num = input_numbers[0];
    i = 1;
    
    /*@ loop invariant 1 <= i && i <= n;
        loop invariant max_num >= min_num;
        loop invariant max_ge_all(max_num, input_numbers, i);
        loop invariant min_le_all(min_num, input_numbers, i);
        loop invariant max_num >= 0;
        loop invariant min_num >= 0;
        loop assigns i, max_num, min_num;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n;
        if (input_numbers[i] > max_num) {
            max_num = input_numbers[i];
        }
        //@ assert max_ge_all(max_num, input_numbers, i+1);
        if (input_numbers[i] < min_num) {
            min_num = input_numbers[i];
        }
        //@ assert min_le_all(min_num, input_numbers, i+1);
        i += 1;
    }
    //@ assert max_num >= min_num;
    return max_num - min_num;
}
