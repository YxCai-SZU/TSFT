#include <stdbool.h>

/*@ predicate is_valid_index(integer i, integer n) =
      i >= 0 && i < n;
*/

/*@ predicate is_valid_value(integer v) =
      v >= 1 && v <= 1000000;
*/

/*@ predicate array_valid_range(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> is_valid_value(arr[i]);
*/

/*@ lemma index_bound: \forall integer i, integer n;
      is_valid_index(i, n) ==> i >= 0 && i < n;
*/

/*@ lemma value_bound: \forall integer v;
      is_valid_value(v) ==> v >= 1 && v <= 1000000;
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(numbers + (0 .. n-1));
    requires array_valid_range(numbers, n);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *numbers)
{
    int current;
    int count;
    int index;
    
    current = numbers[0];
    count = 0;
    index = 1;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> is_valid_value(numbers[i]);
        loop invariant is_valid_value(current);
        loop invariant array_valid_range(numbers, n);
        loop assigns current, count, index;
        loop variant n - index;
    */
    while (index < n)
    {
        //@ assert is_valid_value(current);
        //@ assert is_valid_value(numbers[index]);
        
        if (current <= numbers[index])
        {
            count = count + 1;
            current = numbers[index];
        }
        
        index = index + 1;
    }
    
    return count;
}
