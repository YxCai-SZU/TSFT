int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n >= 0;
requires m >= 0;
requires m < n;
*/
void foo(int n, int m)
{
  assume(n>=0);
  assume(m>=0);
  assume(m<n);
  int x = 0; 
  int y = m;
  while(x < n) {
    x++;
    if(x > m) y++;
  }
  /*@ assert y==n; */
}
