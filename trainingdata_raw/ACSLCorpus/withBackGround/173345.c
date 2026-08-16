#include <stdbool.h>

/*@ predicate is_even_spec(integer n, bool result) =
      result == (n % 2 == 0);
*/

/*@
  requires n >= 0;
  ensures \result <==> (n % 2 == 0);
  assigns \nothing;
*/
bool is_even(int n)
{
    bool is_even_result = true;
    int temp_n = n;

    /*@
      loop invariant temp_n >= 0;
      loop invariant n >= 0;
      loop invariant temp_n % 2 == n % 2;
      loop assigns temp_n;
      loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
    }

    if (temp_n != 0)
    {
        is_even_result = false;
    }

    //@ assert is_even_spec(n, is_even_result);
    return is_even_result;
}

int main(void)
{
    return 0;
}
