// Generated C + ACSL

/*@
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \exists integer k; 0 <= k < a_len && \result == a[k];
    ensures \forall integer i; 0 <= i < a_len ==> \result <= a[i];
*/
int ArrayMin(int* a, int a_len)
{
  int min = a[0];
  /*@ assert \exists integer k; 0 <= k < a_len && min == a[k]; */
  /*@ assert min == a[0]; */
  int i = 1;
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant \exists integer k; 0 <= k < i && min == a[k];
  loop invariant \forall integer j; 0 <= j < i ==> min <= a[j];
  loop assigns i, min;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] < min))
      {
        min = a[i];
        /*@ assert min == a[i]; */
      }
      /*@ assert \exists integer k; 0 <= k <= i && min == a[k]; */
      /*@ assert \forall integer j; 0 <= j <= i ==> min <= a[j]; */
      i = (i + 1);
    }
  /*@ assert i == a_len; */
  /*@ assert \exists integer k; 0 <= k < a_len && min == a[k]; */
  /*@ assert \forall integer j; 0 <= j < a_len ==> min <= a[j]; */
  return min;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a_vals[] = {3, 5, 2, 1, 4};
  int* a = a_vals;
  int a_len = 5;
  int min = ArrayMin(a, a_len);
  /*@ assert (min == 1); */
}