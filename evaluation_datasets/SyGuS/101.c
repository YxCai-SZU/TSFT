void foo(int n) {
  int x = 0;

  while (x < n) {
    x = x + 1;
  }

  if (x != n) {
    /*@ assert n < 0; */
  }
}
