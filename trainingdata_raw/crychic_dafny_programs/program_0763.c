// Generated C + ACSL

/*@
    requires height != \null;
    requires height_len >= 0;
    requires \valid(height + (0 .. height_len-1));
    requires \forall integer i; 0 <= i < height_len ==> height[i] >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int Trap(int* height, int height_len)
{
  if (height_len == 0)
  {
    return 0;
  }
  int left = 0;
  int right = (height_len - 1);
  int leftMax = 0;
  int rightMax = 0;
  int water = 0;
  /*@ assert water >= 0 && water <= 2147483647; */
/*@
  loop invariant 0 <= left <= height_len;
  loop invariant -1 <= right < height_len;
  loop invariant left <= right + 1;
  loop invariant water >= \at(water, LoopEntry);
  loop invariant leftMax >= \at(leftMax, LoopEntry);
  loop invariant rightMax >= \at(rightMax, LoopEntry);
  loop invariant leftMax >= 0;
  loop invariant rightMax >= 0;
  loop invariant \forall integer i; 0 <= i < left ==> leftMax >= height[i];
  loop invariant \forall integer i; right < i < height_len ==> rightMax >= height[i];
  loop assigns left, right, water, leftMax, rightMax;
  loop variant right - left + 1;
*/
  while ((left <= right))
    {
      if ((leftMax <= rightMax))
      {
        leftMax = ((height[left] > leftMax)) ? (height[left]) : (leftMax);
        water = (water + (leftMax - height[left]));
        left = (left + 1);
      }
      else
      {
        rightMax = ((height[right] > rightMax)) ? (height[right]) : (rightMax);
        water = (water + (rightMax - height[right]));
        right = (right - 1);
      }
    }
  return water;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int height[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int result = Trap(height, 12);
  /* unsupported stmt: print "Trapped water: ", result, "\n"; */
}