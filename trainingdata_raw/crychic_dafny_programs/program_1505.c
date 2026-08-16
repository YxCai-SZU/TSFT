// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a_length = 10;
  int a[10];
  int i = 0;
/*@
  loop invariant 0 <= i <= a_length;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] == 0;
  loop assigns i, a[0..a_length-1];
  loop variant a_length - i;
*/
  while ((i < a_length))
    {
      a[i] = 0;
      i = (i + 1);
    }
  int v = a[3];
  /*@ assert (v == 0); */
}