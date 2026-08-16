// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 1;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[\result] >= a[k];
*/
int FindMax(int* a, int a_len)
{
  int index = 1;
  int currentMaxIndex = 0;
  /*@ assert currentMaxIndex >= 0 && currentMaxIndex <= 2147483647; */
/*@
  loop invariant 0 <= currentMaxIndex < index <= a_len;
  loop invariant \forall integer k; 0 <= k < index ==> a[currentMaxIndex] >= a[k];
  loop invariant \valid_read(a + (0 .. a_len - 1));
  loop invariant currentMaxIndex < a_len;
  loop assigns index, currentMaxIndex;
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if ((a[index] > a[currentMaxIndex]))
      {
        currentMaxIndex = index;
      }
      index = (index + 1);
    }
  return currentMaxIndex;  // Dafny implicit return
}

/*@
    requires a != \null;
    requires a_len >= 1;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[\result] <= a[k];
*/
int FindMin(int* a, int a_len)
{
  int index = 1;
  int currentMinIndex = 0;
  /*@ assert currentMinIndex >= 0 && currentMinIndex <= 2147483647; */
/*@
  loop invariant 0 <= currentMinIndex < index <= a_len;
  loop invariant \forall integer k; 0 <= k < index ==> a[currentMinIndex] <= a[k];
  loop invariant currentMinIndex < a_len;
  loop invariant \at(currentMinIndex, LoopEntry) < a_len;
  loop invariant \forall integer k; 0 <= k < \at(index, LoopEntry) ==>
                 a[\at(currentMinIndex, LoopEntry)] <= a[k];
  loop assigns index, currentMinIndex;
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if ((a[index] < a[currentMinIndex]))
      {
        currentMinIndex = index;
      }
      index = (index + 1);
    }
  return currentMinIndex;  // Dafny implicit return
}

/*@
  predicate sorted(int *a, integer len, integer low, integer high) =
    \forall integer j, k; low <= j && j < k && k <= high ==> a[j] <= a[k];
*/
