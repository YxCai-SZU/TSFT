/*@
requires n >= 0;
*/
void foo(int n) {
  int x = n;
  int y = 0;

  while (x > 0) {
    y  = y + 1;
    x  = x - 1;
  }

  /*@ assert n == x + y; */
}
