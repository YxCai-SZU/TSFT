#include <stddef.h>
#include <stdbool.h>

/*@
  requires 1 <= n && n <= 20;
  requires \valid(numbers + (0 .. n-1));
  requires (\forall size_t i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
  ensures \result >= 0;
  ensures \exists size_t idx; 0 <= idx < n && numbers[idx] == \result;
*/
int func(size_t n, int* numbers)
{
    int min;
    size_t i;
    
    min = numbers[0];
    i = 1;
    
    /*@ loop invariant 1 <= i && i <= n;
        loop invariant (\forall size_t i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        loop invariant \exists size_t idx; 0 <= idx < i && numbers[idx] == min;
        loop invariant min >= 1 && min <= 100;
        loop assigns min, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (\forall size_t i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        if (numbers[i] < min) {
            min = numbers[i];
        }
        i++;
    }
    
    //@ assert \exists size_t idx; 0 <= idx < n && numbers[idx] == min;
    return min;
}
