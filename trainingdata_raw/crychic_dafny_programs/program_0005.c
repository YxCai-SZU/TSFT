// Generated C + ACSL

/*@
    requires nums != \null;
    requires nums_len >= 2;
    requires \valid(nums + (0 .. nums_len-1));
    requires \exists integer i, j;
        0 <= i < j < nums_len && nums[i] + nums[j] == target;
    assigns \nothing;
*/
void twoSum(int* nums, int nums_len, int target)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= nums_len;
  loop invariant \forall integer u, v; 0 <= u < v < nums_len && u < i ==> nums[u] + nums[v] != target;
  loop invariant i < nums_len ==> \exists integer u, v; i <= u < v < nums_len && nums[u] + nums[v] == target;
  loop invariant \valid_read(nums + (0..nums_len-1));
  loop assigns i;
  loop variant nums_len - i;
*/
  while ((i < nums_len))
    {
      int j = (i + 1);
/*@
  loop invariant 0 <= i < j <= nums_len;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant j == \at(j, LoopEntry) || (j > \at(j, LoopEntry) && j <= nums_len);
  loop invariant \forall integer u; \at(j, LoopEntry) <= u < j ==> nums[i] + nums[u] != target;
  loop invariant \forall integer u, v; 0 <= u < v < nums_len && u < i ==> nums[u] + nums[v] != target;
  loop assigns j;
  loop variant nums_len - j;
*/
      while ((j < nums_len))
        {
          if (((nums[i] + nums[j]) == target))
          {
            // TODO multiple returns
            return;
          }
          j = (j + 1);
        }
      i = (i + 1);
    }
}
