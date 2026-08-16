#include <stdbool.h>

/*@ predicate is_valid_index(integer i) = 0 <= i < 5; */

/*@ predicate element_matches(int *arr, integer i) =
      arr[i] == i + 1 || arr[i] == 0; */

/*@ predicate exists_zero(int *arr) =
      \exists integer i; 0 <= i < 5 && arr[i] == 0; */

/*@ predicate all_match_until(int *arr, integer v) =
      \forall integer j; 0 <= j < v - 1 ==> arr[j] != 0; */

/*@ lemma zero_exists_in_range:
      \forall int *arr;
      exists_zero(arr) ==>
      \exists integer i; 0 <= i < 5 && arr[i] == 0; */

/*@
  requires \valid(numbers + (0..4));
  requires \forall integer i; 0 <= i < 5 ==> 
           numbers[i] == i + 1 || numbers[i] == 0;
  requires \exists integer i; 0 <= i < 5 && numbers[i] == 0;
  ensures 1 <= \result <= 5;
  ensures numbers[\result - 1] == 0;
*/
int func(int *numbers) {
    int result = 0;
    int v = 1;
    
    /*@
      loop invariant 1 <= v <= 6;
      loop invariant (result == 0 && all_match_until(numbers, v)) ||
                     (1 <= result <= 5 && numbers[result - 1] == 0);
      loop invariant \forall integer i; 0 <= i < 5 ==>
                     numbers[i] == i + 1 || numbers[i] == 0;
      loop invariant \exists integer i; 0 <= i < 5 && numbers[i] == 0;
      loop assigns result, v;
      loop variant 6 - v;
    */
    while (v <= 5) {
        //@ assert 1 <= v <= 5;
        if (numbers[v - 1] == 0) {
            result = v;
        }
        v += 1;
    }
    //@ assert 1 <= result <= 5;
    //@ assert numbers[result - 1] == 0;
    return result;
}
