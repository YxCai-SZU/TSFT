int unknown();

/*@
requires x == y;
*/
void foo(int x, int y) {
  int lock = 1;

  while ((x != y)) {
      if (unknown()) {
        lock  = 1;
        x = y;
      } else {
        lock = 0;
        x = y;
        y = y + 1;
      }
  }

  /*@ assert lock == 1; */
}
