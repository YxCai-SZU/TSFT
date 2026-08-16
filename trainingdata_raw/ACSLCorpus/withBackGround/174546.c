#include <stdbool.h>

/*@ predicate valid_range(integer n) = 0 < n <= 100; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> -100 <= arr[i] <= 100; */
/*@ predicate is_maximum(int max, int *arr, integer n) = 
      \forall integer j; 0 <= j < n ==> max >= arr[j]; */
/*@ predicate exists_in_array(int val, int *arr, integer n) = 
      \exists integer i; 0 <= i < n && val == arr[i]; */

/*@ lemma max_in_range: 
      \forall int *arr, integer n, int max; 
      valid_array(arr, n) && exists_in_array(max, arr, n) ==> -100 <= max <= 100; */

/*@
  requires valid_range(n);
  requires \valid(input_numbers + (0..n-1));
  requires valid_array(input_numbers, n);
  ensures -100 <= \result <= 100;
  ensures exists_in_array(\result, input_numbers, n);
  ensures is_maximum(\result, input_numbers, n);
*/
int func(int n, int *input_numbers) {
    int max_value;
    int i;
    
    max_value = input_numbers[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant valid_array(input_numbers, n);
      loop invariant \forall integer k; 0 <= k < i ==> max_value >= input_numbers[k];
      loop invariant \exists integer k; 0 <= k < i && max_value == input_numbers[k];
      loop invariant -100 <= max_value <= 100;
      loop assigns max_value, i;
    */
    while (i < n) {
        int num = input_numbers[i];
        
        //@ assert -100 <= num <= 100;
        
        if (num > max_value) {
            max_value = num;
        }
        
        //@ assert \forall integer k; 0 <= k < i+1 ==> max_value >= input_numbers[k];
        //@ assert \exists integer k; 0 <= k < i+1 && max_value == input_numbers[k];
        
        i++;
    }
    
    //@ assert is_maximum(max_value, input_numbers, n);
    return max_value;
}
