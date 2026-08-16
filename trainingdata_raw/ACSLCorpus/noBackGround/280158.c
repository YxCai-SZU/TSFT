#include <stdbool.h>

/*@ requires 0 <= a && a <= 10000 && 0 <= b && b <= 10000; 
    ensures \result == ((a * b) % 2 == 1);
    assigns \nothing; */
bool func(unsigned int a, unsigned int b)
{
  // Variable declarations at scope top
  unsigned int product;
  bool is_odd_result = false;
  unsigned int temp_product;

  // Early return for zero cases
  if (a == 0 || b == 0) {
    return false;
  }

  // Overflow safety proof
  //@ assert a * b <= 10000 * 10000;

  product = a * b;
  temp_product = product;

  /*@ loop invariant 0 <= temp_product && temp_product <= product;
      loop invariant temp_product % 2 == product % 2;
      loop assigns temp_product;
      loop variant temp_product; */
  while (temp_product >= 2) {
    temp_product -= 2;
  }

  if (temp_product == 1) {
    is_odd_result = true;
  }

  // Final verification
  //@ assert is_odd_result == (product % 2 == 1);

  return is_odd_result;
}
