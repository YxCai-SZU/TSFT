void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 0;

  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }

  if (i != j) {
    /*@ assert y != 1; */
  }
}
