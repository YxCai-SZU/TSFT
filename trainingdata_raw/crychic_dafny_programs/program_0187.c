// Generated C + ACSL

/*@
  predicate IsEven(integer n) =
    n % 2 == 0;
*/

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\exists integer i; 0 <= i < a_len && a[i] % 2 == 0);
    ensures \result == 0 <==> (\forall integer i; 0 <= i < a_len ==> a[i] % 2 != 0);
*/
int IsProductEven(int* a, int a_len)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant result == 0 || result == 1;
  loop invariant result == 1 ==> (\exists integer k; 0 <= k < i && IsEven(a[k]));
  loop invariant result == 0 ==> (\forall integer k; 0 <= k < i ==> !IsEven(a[k]));
  loop assigns i, result;
  loop variant a_len - i;
*/
    while ((i < a_len))
      {
        if (a[i] % 2 == 0)
        {
          result = 1;
          break;;
        }
        i = (i + 1);
      }
  }
  return result;  // Dafny implicit return
}