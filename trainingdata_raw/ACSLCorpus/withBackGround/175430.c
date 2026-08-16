#include <stdbool.h>

/*@ predicate is_even_divisible(integer a) =
      a % 2 == 0 ==> (a % 3 == 0 || a % 5 == 0);
*/

/*@ predicate all_even_divisible(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==>
        (arr[i] % 2 == 0 ==> (arr[i] % 3 == 0 || arr[i] % 5 == 0));
*/

/*@ lemma index_bound: \forall int *arr, integer n, integer i;
      0 <= i < n && n <= 100 ==> i <= n;
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(numbers + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= numbers[i] <= 1000;
    ensures \result == true <==> all_even_divisible(numbers, n);
*/
bool func(int n, int *numbers)
{
    bool flag = true;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant index > 0 ==> 
            (flag == true ==> 
                \forall integer i; 0 <= i < index && numbers[i] % 2 == 0 ==> 
                    numbers[i] % 3 == 0 || numbers[i] % 5 == 0);
        loop invariant flag == false ==> 
            \exists integer i; 0 <= i < index && numbers[i] % 2 == 0 && 
                !(numbers[i] % 3 == 0 || numbers[i] % 5 == 0);
        loop invariant n > 0 && n <= 100;
        loop invariant \valid(numbers + (0 .. n-1));
        loop invariant \forall integer i; 0 <= i < n ==> 1 <= numbers[i] <= 1000;
        loop invariant index <= n;
        loop assigns flag, index;
        loop variant n - index;
    */
    while (index < n)
    {
        int a = numbers[index];
        if (a % 2 == 0)
        {
            if (a % 3 != 0 && a % 5 != 0)
            {
                flag = false;
            }
        }
        index++;
        //@ assert index <= n;
    }
    return flag;
}
