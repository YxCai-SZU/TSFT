#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_index(integer idx, integer len) = 0 <= idx && idx <= len; */
/*@ predicate is_valid_value(integer v) = 1 <= v && v <= 100; */
/*@ logic integer vector_length(int *arr) = 2; */
/*@ logic integer vector_at(int *arr, integer idx) = arr[idx]; */

/*@ lemma loop_invariant_maintained:
      \forall int *arr, integer idx, integer res;
      is_valid_index(idx, vector_length(arr)) &&
      (idx == 0 ==> res == 0) &&
      (idx == 1 ==> res == vector_at(arr, 0)) &&
      (idx == 2 ==> res == vector_at(arr, 0) - vector_at(arr, 1)) &&
      is_valid_value(vector_at(arr, 0)) &&
      is_valid_value(vector_at(arr, 1)) &&
      idx < vector_length(arr) ==>
      is_valid_index(idx + 1, vector_length(arr)) &&
      (idx + 1 == 1 ==> (res + vector_at(arr, idx) == vector_at(arr, 0))) &&
      (idx + 1 == 2 ==> (res - vector_at(arr, idx) == vector_at(arr, 0) - vector_at(arr, 1)));
*/

/*@ requires 
      vector_length(numbers) == 2 &&
      is_valid_value(vector_at(numbers, 0)) &&
      is_valid_value(vector_at(numbers, 1));
    ensures 
      \result == vector_at(numbers, 0) - vector_at(numbers, 1) + 1;
    assigns \nothing;
*/
int func(int *numbers)
{
    int result = 0;
    size_t index = 0;
    
    /*@ loop invariant 
          is_valid_index(index, vector_length(numbers)) &&
          (index == 0 ==> result == 0) &&
          (index == 1 ==> result == vector_at(numbers, 0)) &&
          (index == 2 ==> result == vector_at(numbers, 0) - vector_at(numbers, 1)) &&
          vector_length(numbers) == 2 &&
          is_valid_value(vector_at(numbers, 0)) &&
          is_valid_value(vector_at(numbers, 1));
        loop assigns result, index;
        loop variant vector_length(numbers) - index;
    */
    while (index < 2)
    {
        int value = numbers[index];
        if (index == 0)
        {
            result = value;
        }
        else
        {
            result -= value;
        }
        index += 1;
    }
    result += 1;
    return result;
}
