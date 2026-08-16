// Generated C + ACSL

/*@
    requires A_len >= 0;
    requires A_len > 0 ==> A != \null;
    requires A_len > 0 ==> \valid_read(A + (0 .. A_len-1));
    assigns \nothing;
    ensures \result >= 0 ==> \result < A_len && A[\result] == key;
    ensures \result < 0 ==> (\forall integer k; 0 <= k < A_len ==> A[k] != key);
*/
int LinealSearch(int* A, int A_len, int key)
{
  int N = A_len;
  int i = 0;
/*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] != key;
  loop assigns i;
  loop variant N - i;
*/
  while ((i < N))
    {
      if (A[i] == key)
      {
        return i;
      }
      i = (i + 1);
    }
  return -1;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int index = LinealSearch(a, 10, 12);
  /* unsupported stmt: print index; */
}