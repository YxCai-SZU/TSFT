// Generated C + ACSL

/*@
    requires x_len > 0;
    requires x != \null;
    requires \valid_read(x + (0 .. x_len-1));
    assigns \nothing;
    ensures \forall integer j; 0 <= j < x_len ==> \result >= x[j];
    ensures \exists integer k; 0 <= k < x_len && \result == x[k];
*/
int max(int* x, int x_len)
{
  int y = x[0];
  //@ assert y == x[0];
  int i = 0;
/*@
  loop invariant 0 <= i <= x_len;
  loop invariant \forall integer j; 0 <= j < i ==> y >= x[j];
  loop invariant \exists integer k; 0 <= k < x_len && y == x[k];
  loop invariant i == 0 ==> y == x[0];
  loop invariant i > 0 ==> (\forall integer j; 0 <= j < i ==> y >= x[j]);
  loop assigns i, y;
  loop variant x_len - i;
*/
  while ((i < x_len))
    {
      if ((y <= x[i]))
      {
        y = x[i];
        //@ assert y == x[i];
        //@ assert \exists integer k; 0 <= k < x_len && y == x[k];
      }
      //@ assert y >= x[i];
      i = (i + 1);
      //@ assert \forall integer j; 0 <= j < i ==> y >= x[j];
    }
  //@ assert i == x_len;
  //@ assert \forall integer j; 0 <= j < x_len ==> y >= x[j];
  //@ assert \exists integer k; 0 <= k < x_len && y == x[k];
  return y;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a_vals[] = {5, 1, 3, 6, 12, 3};
  int* a = a_vals;
  int a_len = 6;
  int c = max(a, a_len);
  /*@ assert (c == 12); */
}