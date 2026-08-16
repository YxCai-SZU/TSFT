int unknown1();
int unknown2();
int unknown3();
int unknown4();

int main() {

  int i, c;
  i = 0;
  c = 0;
  while (i < 1000) {
    c = c + i;
    i = i + 1;
  }

  /*@ assert c >= 0; */
}
