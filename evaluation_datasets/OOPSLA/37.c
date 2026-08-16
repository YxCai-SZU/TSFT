int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n > 0;
*/
void foo(int n) {
  int x = 0;
  int m = 0;
  while (x < n) {
    if (unknown1()) {
      m = x;
    }
    x = x + 1;
  }
  if (n > 0) {
    /*@ assert 0 <= m && m < n; */
  }
}
