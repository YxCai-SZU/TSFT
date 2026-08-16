void foo(int n) {
  int x = n;

  while (x > 1) {
    x  = x - 1;
  }

  if (x != 1) {
    /*@ assert n < 0; */
  }
}
