#include <stdbool.h>

/*@ predicate all_even_divisible_by_3_or_5(integer n, int *numbers) =
      \forall integer i; 0 <= i < n ==> 
        (numbers[i] % 2 == 0 ==> (numbers[i] % 3 == 0 || numbers[i] % 5 == 0));
*/

/*@ predicate valid_numbers(integer n, int *numbers) =
      \forall integer i; 0 <= i < n ==> numbers[i] > 0 && numbers[i] <= 1000;
*/

/*@ lemma flag_implies_divisible:
      \forall integer n, int *numbers, bool flag, integer idx;
      valid_numbers(n, numbers) &&
      (\forall integer j; 0 <= j < idx ==> 
          (numbers[j] % 2 == 0 ==> (numbers[j] % 3 == 0 || numbers[j] % 5 == 0))) &&
      idx == n && flag == true
      ==> 
      all_even_divisible_by_3_or_5(n, numbers);
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(numbers + (0 .. n-1));
    requires valid_numbers(n, numbers);
    ensures \result == true <==> all_even_divisible_by_3_or_5(n, numbers);
    assigns \nothing;
*/
bool func(int n, int *numbers) {
    bool flag = true;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant flag == true <==> 
          (\forall integer j; 0 <= j < i ==> 
            (numbers[j] % 2 == 0 ==> (numbers[j] % 3 == 0 || numbers[j] % 5 == 0)));
        loop assigns flag, i;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        
        if (a % 2 == 0) {
            if (a % 3 != 0 && a % 5 != 0) {
                flag = false;
            }
        }
        
        i++;
    }
    
    //@ assert flag == true <==> all_even_divisible_by_3_or_5(n, numbers);
    return flag;
}
