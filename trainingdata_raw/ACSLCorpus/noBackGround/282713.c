#include <stddef.h>

/*@ requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2); */
size_t func(size_t a, size_t b)
{
  // Variable declarations at scope top
  size_t result;

  //@ assert 1 <= a;
  //@ assert a <= 100;
  //@ assert 1 <= b;
  //@ assert b <= 100;
  //@ assert 1 <= a + b + 1;
  //@ assert a + b + 1 <= 201;
  //@ assert (a + b + 1) / 2 <= 100;

  result = (a + b + 1) / 2;
  return result;
}
