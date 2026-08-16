// Generated C + ACSL

int TwoSum(int nums, int min, int max);
int ReadNumbersFromFile(const char* filename);

/*@
    assigns \nothing;
*/
void Main(void)
{
  int nums = ReadNumbersFromFile("2sum.txt");
  int count1 = TwoSum(nums, -10000, -7500);
  int count2 = TwoSum(nums, -7500, -5000);
  int count3 = TwoSum(nums, -5000, -2500);
  int count4 = TwoSum(nums, -2500, 0);
  int count5 = TwoSum(nums, 0, 2500);
  int count6 = TwoSum(nums, 2500, 5000);
  int count7 = TwoSum(nums, 5000, 7500);
  int count8 = TwoSum(nums, 7500, 10000);
  int totalCount = (((((((count1 + count2) + count3) + count4) + count5) + count6) + count7) + count8);
  /* unsupported stmt: print "Total count: ", totalCount, "\n"; */
}