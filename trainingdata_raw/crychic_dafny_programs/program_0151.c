// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (\forall integer i; 0 <= i < a_len ==> a[i] == n);
    ensures \result == 0 ==>
        (\exists integer i; 0 <= i < a_len && a[i] != n);
*/
int AllElementsEqual(int* a, int a_len, int n)
{
  int result = 1;
  /*@ assert result >= 0 && result <= 2147483647; */
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant result == 0 || result == 1;
  loop invariant result == 1 ==> \forall integer k; 0 <= k < i ==> a[k] == n;
  loop invariant result == 0 ==> \exists integer k; 0 <= k < i && a[k] != n;
  loop invariant result == 0 ==> i < a_len;
  loop invariant result == 0 ==> a[i] != n;
  loop assigns i, result;
  loop variant a_len - i;
*/
    while ((i < a_len))
      {
        if ((a[i] != n))
        {
          result = 0;
          /*@ assert a[i] != n; */
          /*@ assert 0 <= i < a_len; */
          /*@ assert \exists integer k; 0 <= k < a_len && a[k] != n; */
          break;;
        }
        i = (i + 1);
      }
    /*@ assert result == 1 ==> i == a_len; */
    /*@ assert result == 1 ==> \forall integer k; 0 <= k < a_len ==> a[k] == n; */
    /*@ assert result == 0 ==> 0 <= i < a_len && a[i] != n; */
    /*@ assert result == 0 ==> \exists integer k; 0 <= k < a_len && a[k] != n; */
  }
  return result;  // Dafny implicit return
}