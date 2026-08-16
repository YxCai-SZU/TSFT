int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {
  int x, y;

  x = -50;
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  /*@ assert y > 0; */
}
