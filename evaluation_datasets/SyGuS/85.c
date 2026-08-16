int main() {
  int x = -15000;
  int y = 0;

  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }

  /*@ assert y > 0; */
}
