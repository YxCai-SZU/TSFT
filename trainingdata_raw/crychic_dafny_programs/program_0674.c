// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= arr_len;
    ensures \result > 0;
*/
int Candy(int* arr, int arr_len)
{
  int ans = 1;
  int peek = 1;
  int last = 1;
  int acc = 0;
  int result = ans;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 1;
/*@
  loop invariant 1 <= i <= arr_len;
  loop invariant ans > 0;
  loop invariant peek > 0;
  loop invariant last > 0;
  loop invariant acc >= 0;
  loop invariant ans >= i;
  loop invariant result == ans;
  loop invariant i >= \at(i, LoopEntry);
  loop invariant ans >= \at(ans, LoopEntry);
  loop assigns i, ans, peek, last, acc, result;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      if ((arr[i] > arr[(i - 1)]))
      {
        last = (last + 1);
        peek = last;
        ans = (ans + last);
        acc = 0;
      }
      else
      if ((arr[i] == arr[(i - 1)]))
      {
        peek = 1;
        acc = 0;
        last = 1;
        ans = (ans + 1);
      }
      else
      {
        last = 1;
        acc = (acc + 1);
        if ((acc >= peek))
        {
          ans = ((ans + acc) + 1);
          peek = (acc + 1);
        }
        else
        {
          ans = ((ans + acc) + 1);
        }
      }
      i = (i + 1);
      result = ans;
    }
  return result;  // Dafny implicit return
}
