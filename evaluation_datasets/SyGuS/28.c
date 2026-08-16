/*@
requires x == n;
requires x != 0;
*/
void foo(int x, int n) {

  while (x > 0) {
    x  = x - 1;
  }

  if (x != 0) {
    /*@ assert n < 0; */
  }
}
