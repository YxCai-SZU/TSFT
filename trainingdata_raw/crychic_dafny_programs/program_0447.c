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
  //@ assert \forall integer i; 0 <= i < 5 ==> a[i] != 5;
}