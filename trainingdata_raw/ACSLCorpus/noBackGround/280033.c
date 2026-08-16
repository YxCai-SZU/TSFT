#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires N >= 1 && N <= 1000000;
    requires M >= 1 && M <= 10000;
    requires \valid(numbers + (0 .. M-1));
    requires \forall integer i; 0 <= i < M ==> numbers[i] >= 1 && numbers[i] <= 10000;
    assigns \nothing;
    ensures \result >= -1;
    ensures \result >= 0 ==> \result <= N;
*/
int64_t func(int64_t N, int64_t M, int64_t *numbers)
{
    int64_t sum = 0;
    size_t index = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (M) &&
      (sum) >= 0 &&
      (sum) <= (index) * 10000 &&
      \forall integer i; 0 <= i < (index) ==> (numbers)[i] >= 1 && (numbers)[i] <= 10000);
        loop assigns sum, index;
        loop variant M - index;
    */
    while (index < (size_t)M)
    {
        //@ assert numbers[index] >= 1 && numbers[index] <= 10000;
        sum += numbers[index];
        index += 1;
        
        //@ assert sum >= 0;
    }
    
    if (N - sum >= 0)
    {
        //@ assert N - sum >= 0;
        return N - sum;
    }
    else
    {
        return -1;
    }
}
