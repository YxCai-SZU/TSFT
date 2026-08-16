#include <stdint.h>

/*@ requires (1 <= (r) <= 100);
    ensures \result >= 0;
    ensures \result * 100000 <= 2 * r * 314159;
    assigns \nothing; */
int64_t func(int64_t r)
{
  int64_t pi = 314159;
  int64_t circumference = 0;
  int64_t temp = 2 * pi * r;
  int64_t divisor = 100000;

  //@ assert 2 * pi * r <= 2 * 314159 * 100;

  /*@ loop invariant 1 <= r <= 100;
      loop invariant 0 <= circumference;
      loop invariant temp >= 0;
      loop invariant temp + circumference * divisor == 2 * pi * r;
      loop invariant circumference * 100000 <= 2 * r * 314159;
      loop assigns temp, circumference;
      loop variant temp; */
  while (temp >= divisor) {
    temp -= divisor;
    circumference += 1;
  }

  //@ assert circumference * 100000 <= 2 * r * 314159;
  //@ assert temp + circumference * divisor == 2 * pi * r;

  return circumference;
}
