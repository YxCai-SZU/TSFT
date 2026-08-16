// Generated C + ACSL

/*@
    requires nums != \null;
    requires nums_len >= 0;
    requires \valid(nums + (0 .. nums_len-1));
    assigns nums[0 .. nums_len-1];
    ensures 0 <= \result <= nums_len;
    ensures \forall integer k; 0 <= k < \result ==> nums[k] != val;
*/
int RemoveElement(int* nums, int nums_len, int val)
{
  int i = 0;
  int j = 0;
/*@
  loop invariant 0 <= j <= i <= nums_len;
  loop invariant \forall integer k; 0 <= k < j ==> nums[k] != val;
  loop invariant \forall integer k; 0 <= k < j ==>
    \exists integer m; 0 <= m < i && nums[k] == \at(nums[m], LoopEntry);
  loop invariant \forall integer k; i <= k < nums_len ==>
    nums[k] == \at(nums[k], LoopEntry);
  loop invariant \forall integer k; 0 <= k < \at(i, LoopEntry) ==>
    (\at(nums[k], LoopEntry) != val ==>
      \exists integer m; 0 <= m < j && nums[m] == \at(nums[k], LoopEntry));
  loop assigns i, j, nums[0..nums_len-1];
  loop variant nums_len - i;
*/
  while ((i < nums_len))
    {
      if ((nums[i] != val))
      {
        nums[j] = nums[i];
        j = (j + 1);
      }
      i = (i + 1);
    }
  //@ assert \forall integer k; 0 <= k < i ==> \at(nums[k], Pre) == \at(nums[k], Pre);
  //@ assert i == nums_len;
  return j;
}