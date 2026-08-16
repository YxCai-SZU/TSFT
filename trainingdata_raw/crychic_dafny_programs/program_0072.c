// Generated C + ACSL

/*@
    requires a_len > 0;
    requires a != \null;
    requires \valid(a + (0 .. a_len-1));
    requires \forall integer i; 0 <= i < a_len ==> a[i] >= 0;
    assigns \nothing;
*/
void findMax(int* a, int a_len)
{
  int pos = 0;
  /*@ assert pos >= 0 && pos <= 2147483647; */
  int maxVal = a[0];
  /*@ assert maxVal >= 0 && maxVal <= 2147483647; */
  int j = 1;
/*@
  loop invariant 1 <= j <= a_len;
  loop invariant \forall integer i; 0 <= i < j ==> a[i] <= maxVal;
  loop invariant \exists integer i; 0 <= i < j && a[i] == maxVal;
  loop invariant 0 <= pos < a_len;
  loop invariant a[pos] == maxVal;
  loop invariant pos < j;
  loop assigns j, maxVal, pos;
  loop variant a_len - j;
*/
  while ((j < a_len))
    {
      if ((a[j] > maxVal))
      {
        maxVal = a[j];
        pos = j;
      }
      j = (j + 1);
    }
  return;
}
