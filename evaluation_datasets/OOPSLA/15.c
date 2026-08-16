int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n > 0;
requires k > n;
*/
int foo(int n, int k) {

  int i, j;

  j = 0;
  while( j < n ) {
    j++;
    k--;
  } 
  /*@ assert k>=0; */
  return 0;
}
