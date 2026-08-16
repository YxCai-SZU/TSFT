// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer i; 0 <= i < a_len ==> a[\result] <= a[i];
*/
int FindMinIndex(int* a, int a_len)
{
  int idx = 0;
  /*@ assert idx >= 0 && idx <= 2147483647; */
  int j = 1;
/*@
  loop invariant 1 <= j <= a_len;
  loop invariant 0 <= idx < a_len;
  loop invariant \forall integer k; 0 <= k < j ==> a[idx] <= a[k];
  loop invariant idx < j;
  loop assigns j, idx;
  loop variant a_len - j;
*/
  while ((j < a_len))
    {
      if ((a[j] < a[idx]))
      {
        idx = j;
      }
      j = (j + 1);
    }
  return idx;  // Dafny implicit return
}

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer i; 0 <= i < a_len ==> a[\result] >= a[i];
*/
int FindMaxIndex(int* a, int a_len)
{
  int idx = 0;
  /*@ assert idx >= 0 && idx <= 2147483647; */
  int j = 1;
/*@
  loop invariant 1 <= j <= a_len;
  loop invariant 0 <= idx < a_len;
  loop invariant \forall integer k; 0 <= k < j ==> a[idx] >= a[k];
  loop invariant \at(idx, LoopEntry) == idx || (j > \at(j, LoopEntry) && 0 <= idx < a_len);
  loop assigns j, idx;
  loop variant a_len - j;
*/
  while ((j < a_len))
    {
      if ((a[j] > a[idx]))
      {
        idx = j;
      }
      j = (j + 1);
    }
  return idx;  // Dafny implicit return
}

/*@
    requires nums != \null;
    requires nums_len > 0;
    requires \valid_read(nums + (0 .. nums_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= nums_len;
*/
int MinimumDeletions(int* nums, int nums_len)
{
  int a = FindMinIndex(nums, nums_len);
  int b = FindMaxIndex(nums, nums_len);
  if ((a > b))
  {
    /* unsupported stmt: a, b := b, a; */
  }
  int option1 = ((a + 1) + (nums_len - b));
  int option2 = (b + 1);
  int option3 = (nums_len - a);
  int result = option1;
  /*@ assert result >= 0 && result <= 2147483647; */
  if ((option2 < result))
  {
    result = option2;
  }
  if ((option3 < result))
  {
    result = option3;
  }
  return result;  // Dafny implicit return
}
