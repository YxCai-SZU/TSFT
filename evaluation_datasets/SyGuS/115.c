int unknown();

int main() {
  int sn = 0;
  int x = 0;

  while (unknown()) {
    x  = x + 1;
    sn  = sn + 1;
  }

  if (sn != -1) {
    /*@ assert sn == x; */
  }
}
