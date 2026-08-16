int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {
  int i,j,k,n;
  
  for (i=0;i<n;i++)
    for (j=i;j<n;j++)
      for (k=j;k<n;k++){
	      /*@ assert k>=i; */
      }
}
