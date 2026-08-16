#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = -40 <= x <= 40; */

/*@ lemma max_property: \forall integer x, integer max_val;
      is_valid_range(x) && max_val == (x > 30 ? x : 30) ==> max_val >= 30; */

/*@ requires is_valid_range(x);
    ensures \result == (x >= 30); */
bool func(long x)
{
  long max_value;
  bool result;
  int i = 0;
  
  max_value = x > 30 ? x : 30;
  
  //@ assert max_value == (x > 30 ? x : 30);
  
  /*@ loop invariant 0 <= i <= 10;
      loop invariant is_valid_range(x);
      loop invariant max_value == (x > 30 ? x : 30);
      loop invariant max_value >= 30;
      loop assigns i;
      loop variant 10 - i; */
  while (i < 10) {
    (void)max_value;
    i++;
  }
  
  //@ assert max_value >= 30;
  
  result = x >= 30 ? true : false;
  
  return result;
}
