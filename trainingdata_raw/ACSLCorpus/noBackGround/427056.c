#include <stdbool.h>

/*@
  requires (1 <= (n) && (n) <= 20 &&
      1 <= (a) && (a) <= 50 &&
      1 <= (b) && (b) <= 50);
  ensures \result == (n * a >= b);
  assigns \nothing;
*/
bool func(int n, int a, int b)
{
    int product;
    
    //@ assert 1 <= n * a && n * a <= 1000;
    product = n * a;
    //@ assert product == n * a;
    return product >= b;
}
