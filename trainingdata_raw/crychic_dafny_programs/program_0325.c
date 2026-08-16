// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[10];
  int i = 0;
  /*@
    loop invariant 0 <= i <= 10;
    loop invariant \forall int k; 0 <= k < i ==> a[k] == 0;
    loop assigns i, a[0 .. 9];
    loop variant 10 - i;
  */
  for (i = 0; i < 10; i++) {
    a[i] = 0;
  }
  /*@ assert \forall int k; 0 <= k < 10 ==> a[k] == 0; */
  /*@ assert 0 <= 3 < 10; */
  /*@ assert a[3] == 0; */
  int v = a[3];
  /*@ assert (v == 0); */
}