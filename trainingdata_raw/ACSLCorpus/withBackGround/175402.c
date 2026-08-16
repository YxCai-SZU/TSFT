#include <stdbool.h>

/*@ logic integer func(integer k) = k * 2 + 5; */

/*@ predicate even(integer x) = x % 2 == 0; */

/*@
  requires n >= 0;
  ensures \result == 0 || \result == 1;
*/
int is_even(int n)
{
    int is_even_result = 0;
    int temp_n = n;
    
    /*@
      loop invariant temp_n >= 0;
      loop invariant temp_n <= n;
      loop invariant temp_n % 2 == n % 2;
      loop assigns temp_n;
    */
    while (temp_n > 1)
    {
        temp_n -= 2;
    }
    
    if (temp_n == 0)
    {
        is_even_result = 1;
    }
    
    return is_even_result;
}

int main()
{
    return 0;
}
