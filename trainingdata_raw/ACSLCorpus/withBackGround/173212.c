#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_divisible_by_3_or_5{L}(size_t n, int *numbers) =
      \forall integer x; 0 <= x < n ==>
        (numbers[x] % 2 == 0 ==> numbers[x] % 3 == 0 || numbers[x] % 5 == 0);
 */

/*@ predicate valid_numbers{L}(size_t n, int *numbers) =
      n >= 2 && n <= 100000 &&
      \forall integer i; 0 <= i < n ==> 1 <= numbers[i] && numbers[i] <= 1000;
 */

/*@ lemma even_divisible_lemma:
      \forall integer a; a % 2 == 0 && a % 3 != 0 && a % 5 != 0 ==>
        !(a % 3 == 0 || a % 5 == 0);
 */

/*@ requires n >= 2 && n <= 100000;
    requires \valid_read(numbers + (0 .. n-1));
    requires valid_numbers(n, numbers);
    ensures \result == true <==> all_even_divisible_by_3_or_5(n, numbers);
 */
bool func(size_t n, const int *numbers)
{
    size_t i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==>
          (numbers[j] % 2 == 0 ==> numbers[j] % 3 == 0 || numbers[j] % 5 == 0);
        loop assigns i;
        loop variant n - i;
     */
    while (i < n)
    {
        int a = numbers[i];
        if (a % 2 == 0)
        {
            if (a % 3 != 0 && a % 5 != 0)
            {
                //@ assert !(a % 3 == 0 || a % 5 == 0);
                return false;
            }
        }
        i++;
    }
    //@ assert all_even_divisible_by_3_or_5(n, numbers);
    return true;
}
