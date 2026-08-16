#include <stdbool.h>

/*@ predicate is_valid_range(int* arr, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] <= 123;
*/

/*@ predicate condition_holds(int* arr, integer idx) =
    \forall integer i; 0 <= i < idx ==> arr[i] <= arr[i+1] || arr[i] - 1 <= arr[i+1];
*/

/*@ lemma k_in_range:
    \forall integer k; 0 <= k && k <= 123 ==> 0 <= k && k <= 123;
*/

/*@
    requires is_valid_range(input, 5) && 0 <= k && k <= 123;
    ensures \result == true <==> condition_holds(input, 4);
*/
bool func(int* input, int k)
{
    bool flag = true;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= 4;
        loop invariant is_valid_range(input, 5);
        loop invariant 0 <= k && k <= 123;
        loop invariant flag == true <==> condition_holds(input, index);
        loop assigns flag, index;
    */
    while (index < 4)
    {
        int current = input[index];
        int next = input[index + 1];
        
        //@ assert 0 <= current && current <= 123;
        //@ assert 0 <= next && next <= 123;
        
        if (next < current - 1)
        {
            flag = false;
        }
        
        index++;
    }
    
    return flag;
}
