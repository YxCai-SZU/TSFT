// Generated C + ACSL

/*@
    requires n == A_len;
    requires n >= 0;
    requires A != \null;
    requires \valid(A + (0 .. A_len-1));
    assigns A[0 .. A_len-1];
*/
void sort(int* A, int A_len, int n)
{
  int k = 0;
/*@
  loop invariant 0 <= k <= n;
  loop invariant \forall integer i; 0 <= i < k ==> A[i] == i;
  loop assigns k, A[0..n-1];
  loop variant n - k;
*/
  while ((k < n))
    {
      A[k] = k;
      k = (k + 1);
    }
}
