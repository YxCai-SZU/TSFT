int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n >= 0;
*/
void foo(int n) {
  int i, sum = 0;
  assume(n >= 0);

  for (i = 0; i < n; ++i)
    sum = sum + i;

  /*@ assert sum >= 0; */
}
