// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 1;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
*/
void PrintConsecutiveDifferences(int* arr, int arr_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len - 1;
  loop invariant arr_len >= 1;
  loop invariant \valid(arr + (0..arr_len-1));
  loop assigns i;
  loop variant arr_len - 1 - i;
*/
  while ((i < (arr_len - 1)))
    {
      int diff = (arr[(i + 1)] - arr[i]);
      /* unsupported stmt: print diff, "\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int arr[4];
  arr[0] = 100;
  arr[1] = 200;
  arr[2] = 400;
  arr[3] = 800;
  PrintConsecutiveDifferences(arr, 4);
}