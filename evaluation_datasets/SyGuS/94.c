/*@
requires n >= 0;
requires k >= 0;
*/
void foo(int k, int n) {
  int i = 0;
  int j = 0;

  while (i <= n) {
    i  = i + 1;
    j  = j + i;
  }

  /*@ assert i + j + k > 2*n; */
}
