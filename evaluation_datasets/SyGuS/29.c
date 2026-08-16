/*@
requires x == n;
requires n >= 0;
*/
void foo(int x, int n) {

  while (x > 0) {
    x  = x - 1;
  }

  if (n >= 0) {
    /*@ assert x == 0; */
  }
}
