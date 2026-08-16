#include <stddef.h>

/*@
    predicate count_invariant(integer idx, integer cnt, integer n, int *numbers) =
        idx <= n &&
        cnt <= idx &&
        \valid(numbers + (0..n-1)) &&
        \forall integer k; 0 <= k < idx ==> ((k % 2 == 0 && numbers[k] % 2 == 1) ==> cnt <= idx);
*/

/*@
    lemma loop_decreases_positive:
        \forall integer n, integer idx;
            idx < n ==> n - idx > 0;
*/

/*@
    lemma loop_decreases_decreasing:
        \forall integer n, integer idx;
            idx < n ==> n - (idx + 1) < n - idx;
*/

/*@ requires n > 0;
    requires \valid(numbers + (0..n-1));
    ensures \result <= n;
 */
size_t func(size_t n, int *numbers)
{
    size_t count = 0;
    size_t index = 0;
    
    /*@ loop invariant count_invariant(index, count, n, numbers);
        loop assigns index, count;
        loop variant n - index;
     */
    while (index < n)
    {
        int a = numbers[index];
        
        //@ assert index % 2 == 0 ==> (a % 2 == 1 ==> count <= index);
        
        if (index % 2 == 0 && (a % 2) == 1)
        {
            count += 1;
        }
        
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
