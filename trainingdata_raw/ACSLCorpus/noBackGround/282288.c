#include <stdbool.h>

/*@
  requires ((len) >= 4 &&
      (1 <= ((v)[0]) <= 10000) &&
      (1 <= ((v)[1]) <= 10000) &&
      (1 <= ((v)[2]) <= 10000) &&
      (1 <= ((v)[3]) <= 10000));
  ensures \result == ((v[0]) * (v[1])) || \result == ((v[2]) * (v[3]));
  ensures \result >= 1;
*/
int func(int* v, int len)
{
  int a;
  int b;
  int c;
  int d;
  int product1;
  int product2;
  int max_value;

  a = v[0];
  b = v[1];
  c = v[2];
  d = v[3];

  //@ assert (1 <= (a) <= 10000);
  //@ assert (1 <= (b) <= 10000);
  //@ assert (1 <= (c) <= 10000);
  //@ assert (1 <= (d) <= 10000);

  //@ assert ((a) * (b)) <= 10000 * 10000;
  product1 = a * b;

  //@ assert ((c) * (d)) <= 10000 * 10000;
  product2 = c * d;

  //@ assert product1 >= 1;
  //@ assert product2 >= 1;

  //@ assert product1 == ((v[0]) * (v[1]));
  //@ assert product2 == ((v[2]) * (v[3]));

  if (product1 > product2) {
    max_value = product1;
  } else {
    max_value = product2;
  }

  return max_value;
}
