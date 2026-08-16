// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result > 0 ==>
        (\exists integer i; 0 <= i < arr_len && arr[i] == \result);
    ensures \result > 0 ==> \result > 0;
    ensures \result <= 0 ==>
        (\forall integer i; 0 <= i < arr_len ==> arr[i] <= 0);
*/
int FindFirstPositive(int* arr, int arr_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= 0;
  loop assigns i;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      if ((arr[i] > 0))
      {
        return arr[i];
      }
      i = (i + 1);
    }
  return 0;
}