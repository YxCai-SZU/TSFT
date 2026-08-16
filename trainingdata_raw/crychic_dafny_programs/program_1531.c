// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i; 0 <= i < a_len ==> a[i] % 2 == 0;
*/
void getEven(int *a, int a_len)
{
  int index = 0;
/*@
  loop invariant 0 <= index <= a_len;
  loop invariant \forall integer j; 0 <= j < index ==> a[j] % 2 == 0;
  loop assigns index, a[0 .. a_len-1];
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if (((a[index] % 2) != 0))
      {
        a[index] = (a[index] + 1);
      }
      index = (index + 1);
    }
}