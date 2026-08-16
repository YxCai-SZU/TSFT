/*@
requires x == n;
requires x != 1;
*/
void foo(int x, int n) {

  while (x > 1) {
    x  = x - 1;
  }

  if (x != 1) {
    /*@ assert n < 0; */
  }
}
