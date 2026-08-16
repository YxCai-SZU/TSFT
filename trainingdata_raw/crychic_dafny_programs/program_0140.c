// Generated C + ACSL

/*@
    requires nums != \null;
    requires nums_len > 1;
    requires \valid(nums + (0 .. nums_len-1));
    requires \exists integer i, j; 0 <= i < j < nums_len && nums[i] + nums[j] == target;
    assigns \nothing;
*/
void twoSum(int* nums, int nums_len, int target)
{
  int n = nums_len;
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int j = 1;
  /*@ assert j >= 0 && j <= 2147483647; */
/*@
  loop invariant 0 <= i < n;
  loop invariant \forall integer ii, jj; 0 <= ii < i && ii < jj < n ==> nums[ii] + nums[jj] != target;
  loop assigns i, j;
  loop variant n - 1 - i;
*/
  while ((i < (n - 1)))
    {
      j = (i + 1);
      /*@ assert j == i + 1; */
      /*@ assert i + 1 <= n; */
/*@
  loop invariant 0 <= i < j <= n;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant i + 1 <= j;
  loop invariant \forall integer jj; i + 1 <= jj < j ==> nums[i] + nums[jj] != target;
  loop assigns j;
  loop variant n - j;
*/
      while ((j < n))
        {
          /*@ assert i < j < n; */
          if (((nums[i] + nums[j]) == target))
          {
            return;
          }
          /*@ assert nums[i] + nums[j] != target; */
          j = (j + 1);
        }
      /*@ assert j == n; */
      /*@ assert \forall integer jj; i + 1 <= jj < n ==> nums[i] + nums[jj] != target; */
      i = (i + 1);
    }
}