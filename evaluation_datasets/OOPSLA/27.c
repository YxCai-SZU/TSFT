/*@
requires l > 0;
*/
void foo(int l) {
  int i, k, n;
  assume(l > 0);

  for (k = 1; k < n; k++) {
    for (i = l; i < n; i++) {

    }
    for (i = l; i < n; i++) {
      /*@ assert 1 <= k; */
    }
  }

}
