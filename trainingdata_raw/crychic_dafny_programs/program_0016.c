// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (\forall integer i; 0 <= i < a_len ==> n > a[i]);
    ensures \result == 0 ==>
        (\exists integer i; 0 <= i < a_len && n <= a[i]);
*/
int IsGreater(int n, int* a, int a_len)
{
  int result = 1;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant result == 1 ==> \forall integer k; 0 <= k < i ==> n > a[k];
  loop invariant result == 0 ==> \exists integer k; 0 <= k < i && n <= a[k];
  loop invariant result == 0 || result == 1;
  loop assigns i, result;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((n <= a[i]))
      {
        result = 0;
        break;;
      }
      i = (i + 1);
    }
  return result;  // Dafny implicit return
}
