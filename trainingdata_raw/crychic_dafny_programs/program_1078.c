// Generated C + ACSL

/*@
    requires \valid(arr + (0 .. arr_len-1));
    requires arr_len >= 0;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
*/
void PrintArrayElements(int* arr, int arr_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], LoopEntry);
  loop assigns i;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      /* unsupported stmt: print arr[i], "\n"; */
      i = (i + 1);
    }
}
