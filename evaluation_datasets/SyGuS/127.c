void foo(int x, int y) {
  int i = x;
  int j = y;

  while (x != 0) {
    x  = x - 1;
    y  = y - 1;
  }

  if (y != 0) {
    /*@ assert i != j; */
  }
}
