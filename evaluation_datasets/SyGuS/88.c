int unknown();

void foo(int x) {
  int lock = 0;
  int y = x + 1;

  while (x != y) {
    if (unknown()) {
      lock = 1;
      x = y;
    } else {
      lock = 0;
      x = y;
      y = y + 1;
    }
  }

  /*@ assert lock == 1; */
}
