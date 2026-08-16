int main() {
  int i = 1;
  int sn = 0;

  while (i <= 8) {
    i = i + 1;
    sn = sn + 1;
  }

  if (sn != 8) {
    /*@ assert sn == 0; */
  }
}
