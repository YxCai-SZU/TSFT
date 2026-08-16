int unknown1();
int unknown2();
int unknown3();
int unknown4();

void foo(int i, int j) {
  
  int x = i;
  int y = j;
 
  while(x != 0) {
	  x--;
	  y--;
  }
  if(i==j) {
	  /*@ assert y==0; */
  }
}
