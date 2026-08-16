void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 2;

  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }

  if (y == 1) {
    /*@ assert i == j; */
  }
}
