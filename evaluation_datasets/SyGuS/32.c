/*@
requires n >= 0;
*/
void foo(int n) {
  int x = n;

  while (x > 1) {
    x  = x - 1;
  }

  if (n >= 0) {
    /*@ assert x == 1; */
  }
}
