int unknown1();
int unknown2();
int unknown3();
int unknown4();

int main() {
  int a = 0;
  int j;
  int m;
  if(m<=0)
    return 0;
  for(j = 1; j <= m ; j++){
    if(unknown1()) 
       a++;
    else
       a--; 
  }
  /*@ assert a>=-m; */
  /*@ assert a<=m; */
}
