#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_element(integer v) = v == 0 || v == 1; */

/*@ predicate array_valid(int *arr, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> is_valid_element(arr[i]); */

/*@ lemma count_bounds:
    \forall int *arr, integer len, integer idx, integer cnt;
    array_valid(arr, len) &&
    0 <= idx <= len &&
    0 <= cnt <= idx ==>
    cnt >= 0 && cnt <= len; */

/*@ requires 
    \valid_read(numbers + (0 .. 2)) &&
    array_valid(numbers, 3); 
   ensures 
    \result >= 0 && \result <= 3; 
   assigns \nothing;
*/
int func(int *numbers)
{
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 
        0 <= index <= 3 && 
        count >= 0 && count <= (int)index && 
        \forall integer i; 0 <= i < index ==> is_valid_element(numbers[i]); 
      loop assigns 
        count, index; 
    @*/
    while (index < 3)
    {
        int value = numbers[index];
        //@ assert is_valid_element(value);
        
        if (value == 1)
        {
            count += 1;
        }
        
        index += 1;
    }
    
    //@ assert count >= 0 && count <= 3;
    return count;
}
