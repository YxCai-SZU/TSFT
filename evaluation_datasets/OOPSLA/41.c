/*@
ensures \result >= 0;
*/
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n > 0;
*/
void foo(int n, int flag) {
  assume(n >= 0);
  int k = 1;
  if (flag) {
    k = unknown1();
    assume(k >= 0);
  }
  int i = 0, j = 0;
  while (i <= n) {
    i++;
    j += i;
  }
  int z = k + i + j;
  /*@ assert z > 2 * n; */
}
