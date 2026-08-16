int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n > 0;
*/
void foo(int n) {
  int x= 0;
  while(x<n) {
    x++;
  } 
  if(n>0) {
    /*@ assert x==n; */
  }
}
