// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer j; 0 <= j < a_len ==> a[j] <= a[\result];
*/
int FindMax(int* a, int a_len)
{
  int j = 0;
  /*@ assert j >= 0 && j <= 2147483647; */
  int max = a[0];
  int maxIndex = 0;
  /*@ assert maxIndex >= 0 && maxIndex <= 2147483647; */
  /*@ assert maxIndex == 0 && j == 0; */
/*@
  loop invariant 0 <= j <= a_len;
  loop invariant 0 <= maxIndex < a_len;
  loop invariant maxIndex <= j;
  loop invariant \forall integer k; 0 <= k < j ==> max >= a[k];
  loop invariant max == a[maxIndex];
  loop assigns j, maxIndex, max;
  loop variant a_len - j;
*/
  while ((j < a_len))
    {
      if ((a[j] > max))
      {
        maxIndex = j;
        max = a[j];
        /*@ assert maxIndex == j; */
        /*@ assert max == a[maxIndex]; */
      }
      /*@ assert maxIndex <= j; */
      j = (j + 1);
      /*@ assert maxIndex < j; */
    }
  /*@ assert j == a_len; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] <= a[maxIndex]; */
  return maxIndex;  // Dafny implicit return
}