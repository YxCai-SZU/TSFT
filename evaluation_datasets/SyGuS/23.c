/*@
requires i == 1;
requires j == 20;
*/
void foo(int i, int j) {

  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }

  /*@ assert j == 13; */
}
