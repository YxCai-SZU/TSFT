// Generated C + ACSL

/*@
    requires a != \null;
    requires b != \null;
    requires \separated(a + (0 .. a_len-1), b + (0 .. b_len-1));
    requires a_len == b_len;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \valid(b + (0 .. b_len-1));
    assigns b[0 .. b_len-1];
*/
void copy_neg(int* a, int a_len, int* b, int b_len)
{
  int i = 0;
  int r = 0;
/*@
  loop invariant 0 <= r <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> (a[j] < 0 ==> (\exists integer k; 0 <= k < r && b[k] == a[j]));
  loop invariant \forall integer k; 0 <= k < r ==> (\exists integer j; 0 <= j < i && a[j] == b[k] && a[j] < 0);
  loop invariant r <= i;
  loop assigns i, r, b[0..a_len-1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] < 0))
      {
        b[r] = a[i];
        r = (r + 1);
      }
      i = (i + 1);
    }
}