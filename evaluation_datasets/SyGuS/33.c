/*@
requires n < 0;
*/
void foo(int n) {
  int x = n;

  while (x > 0) {
    x  = x - 1;
  }

  if (x != 0) {
    /*@ assert n < 0; */
  }
}
