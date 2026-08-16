/*@
requires (x == 10000);
*/
void foo(int x) {

  while ((x > 0)) {
    (x  = (x - 1));
  }

  /*@ assert (x == 0); */
}
