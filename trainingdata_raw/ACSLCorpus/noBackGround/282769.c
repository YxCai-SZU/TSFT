#include <stdbool.h>

/*@
  requires \true;
  ensures ((\result) <= (a) && (\result) <= (b) && (\result) <= (c));
*/
int min_of_three(int a, int b, int c)
{
   int ret;
   //@ assert \true;
   if (a <= b && a <= c) {
      ret = a;
   } else if (b <= a && b <= c) {
      ret = b;
   } else {
      ret = c;
   }
   //@ assert ((ret) <= (a) && (ret) <= (b) && (ret) <= (c));
   return ret;
}

/*@
  requires (1 <= (a) && (a) <= 10000 && 1 <= (b) && (b) <= 10000);
  ensures \result == (a * b % 2 == 0);
*/
bool func(int a, int b)
{
   //@ assert (1 <= (a) && (a) <= 10000 && 1 <= (b) && (b) <= 10000);
   //@ assert 1 <= a * b <= 10000 * 10000;
   int product = a * b;
   bool is_even = false;
   int abs_product;
   if (product < 0) {
      abs_product = -product;
   } else {
      abs_product = product;
   }
   /*@
     loop invariant 0 <= abs_product <= 10000 * 10000;
     loop invariant (1 <= (a) && (a) <= 10000 && 1 <= (b) && (b) <= 10000);
     loop invariant abs_product <= product;
     loop invariant abs_product % 2 == product % 2;
     loop invariant 1 <= a * b <= 10000 * 10000;
     loop assigns abs_product;
   */
   while (abs_product >= 2) {
      //@ assert abs_product >= 2;
      abs_product -= 2;
   }
   if (abs_product == 0) {
      is_even = true;
   }
   //@ assert is_even == (a * b % 2 == 0);
   return is_even;
}
