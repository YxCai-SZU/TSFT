#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100000;
  requires \valid(input_numbers + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= (n) &&
      \forall size_t i, j; 0 <= i < j < (n) ==> (input_numbers)[i] != (input_numbers)[j]);
  ensures \result >= -1 && \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, int *input_numbers)
{
    size_t x = 1;
    int count = 0;
    size_t index = 0;
    
    //@ assert (0 <= (index) <= (n) &&       1 <= (x) <= (index) + 1 &&       0 <= (count) <= (int)(index) &&       ((index) > 0 ==> \forall size_t i; 0 <= i < (index) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= (n)) &&       ((index) > 0 ==> \forall size_t i, j; 0 <= i < j < (index) ==> (input_numbers)[i] != (input_numbers)[j]) &&       (n) >= 1 && (n) <= 100000);
    
    /*@ loop invariant (0 <= (index) <= (n) &&
      1 <= (x) <= (index) + 1 &&
      0 <= (count) <= (int)(index) &&
      ((index) > 0 ==> \forall size_t i; 0 <= i < (index) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= (n)) &&
      ((index) > 0 ==> \forall size_t i, j; 0 <= i < j < (index) ==> (input_numbers)[i] != (input_numbers)[j]) &&
      (n) >= 1 && (n) <= 100000);
        loop assigns index, x, count;
        loop variant n - index;
    */
    while (index < n)
    {
        int a = input_numbers[index];
        
        if (a == (int)x)
        {
            x = x + 1;
        }
        else
        {
            count = count + 1;
        }
        
        index = index + 1;
        
        //@ assert (0 <= (index) <= (n) &&       1 <= (x) <= (index) + 1 &&       0 <= (count) <= (int)(index) &&       ((index) > 0 ==> \forall size_t i; 0 <= i < (index) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= (n)) &&       ((index) > 0 ==> \forall size_t i, j; 0 <= i < j < (index) ==> (input_numbers)[i] != (input_numbers)[j]) &&       (n) >= 1 && (n) <= 100000);
    }
    
    //@ assert 0 <= count <= (int)n;
    
    int result;
    if (count == (int)n)
    {
        result = -1;
    }
    else
    {
        result = count;
    }
    
    //@ assert result >= -1 && result <= (int)n;
    return result;
}
