// Generated C + ACSL

/*@
    requires 0 < n <= a_len;
    requires a != \null;
    requires \valid_read(a + (0 .. n-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < n && a[i] == \result;
    ensures \forall integer i; 0 <= i < n ==> a[i] >= \result;
*/
int min(int* a, int a_len, int n)
{
  int i;
  int min = a[0];
  /*@ assert min == a[0]; */
  i = 1;
/*@
  loop invariant 1 <= i <= n;
  loop invariant \exists integer j; 0 <= j < i && a[j] == min;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] >= min;
  loop assigns i, min;
  loop variant n - i;
*/
  while ((i < n))
    {
      if ((a[i] < min))
      {
        min = a[i];
      }
      /*@ assert \exists integer j; 0 <= j <= i && a[j] == min; */
      /*@ assert \forall integer j; 0 <= j <= i ==> a[j] >= min; */
      i = (i + 1);
    }
  /*@ assert i == n; */
  /*@ assert \exists integer j; 0 <= j < n && a[j] == min; */
  /*@ assert \forall integer j; 0 <= j < n ==> a[j] >= min; */
  return min;  // Dafny implicit return
}