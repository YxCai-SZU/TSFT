// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i; 0 <= i < a_len ==> a[i] % 2 == 0;
*/
void GetEven(int* a, int a_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] % 2 == 0;
  loop assigns i, a[0..a_len-1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if (((a[i] % 2) != 0))
      {
        a[i] = (a[i] + 1);
      }
      i = (i + 1);
    }
}
