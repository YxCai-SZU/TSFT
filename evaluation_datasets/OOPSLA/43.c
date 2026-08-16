int unknown1();
int unknown2();
int unknown3();
int unknown4();

int foo(int x, int y)
{
  int i=0;
  int t=y;
   
  if (x==y) return x;
  
  while (unknown1()){
    if (x > 0)   
      y = y + x;
  }
   
  /*@ assert y >= t; */
  return 0;
}
