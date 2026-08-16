int unknown();

/*@
requires x >= 0;
requires y >= 0;
requires x >= y;
*/
void foo(int x, int y) {
  int i = 0;

  while (unknown()) {
    if (i < y)
    {
      i = i + 1;
    }
  }

  if (i >= x) {
    if (0 > i) {
      /*@ assert i >= y; */
    }
  }
}
