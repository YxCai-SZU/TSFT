int unknown();

/*@
requires y >= 127;
*/
void foo(int y) {
  int c = 0;
  int z = 36 * y;

  while (unknown()) {
    if (c < 36)
    {
      z = z + 1;
      c = c + 1;
    }
  }

  if(c < 36) {
    /*@ assert z < 4608; */
  }
}
