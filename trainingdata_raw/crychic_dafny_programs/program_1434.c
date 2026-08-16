// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[5];
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  a[3] = 3;
  a[4] = 4;
  int *s = a;
  /*@ assert s == a; */
  /*@ assert \valid(a + (0 .. 4)); */
  /*@ assert a[0] == 0; */
  /*@ assert \forall integer i; 0 <= i < 5 ==> a[i] != 10; */
  /*@ assert a[3] == 3; */
  /*@ assert \exists integer i; 0 <= i < 5 && a[i] == 3; */
}