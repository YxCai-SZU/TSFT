// Generated C + ACSL

/*@
    requires a != \null;
    requires b != \null;
    requires a_len >= 0;
    requires b_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \valid_read(b + (0 .. b_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        ((a_len <= b_len &&
          (\forall integer i; 0 <= i < a_len ==> a[i] == b[i])) ||
         (\exists integer k; 0 <= k < a_len && k < b_len &&
          (\forall integer j; 0 <= j < k ==> a[j] == b[j]) &&
          a[k] < b[k]));
    ensures \result == 0 <==>
        !(((a_len <= b_len &&
            (\forall integer i; 0 <= i < a_len ==> a[i] == b[i])) ||
           (\exists integer k; 0 <= k < a_len && k < b_len &&
            (\forall integer j; 0 <= j < k ==> a[j] == b[j]) &&
            a[k] < b[k])));
*/
int leq(int* a, int a_len, int* b, int b_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant 0 <= i <= b_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
  loop assigns i;
  loop variant a_len - i;
*/
  while (((i < a_len) && (i < b_len)))
    {
      if ((a[i] < b[i]))
      {
        return 1;
      }
      else
      if ((a[i] > b[i]))
      {
        return 0;
      }
      else
      {
        i = (i + 1);
      }
    }
  return (a_len <= b_len);
}

/*@
    assigns \nothing;
*/
void testLeq(void)
{
  int b_vals[] = {1, 2};
  int* b = b_vals;
  int b_len = 2;
  int a1_vals[] = {1};
  int* a1 = a1_vals;
  int a1_len = 1;
  int r1 = leq(a1, a1_len, b, b_len);
  /*@ assert r1; */
  int a2_vals[] = {1};
  int* a2 = a2_vals;
  int a2_len = 1;
  int r2 = leq(a2, a2_len, b, b_len);
  /*@ assert r2; */
  int a3_vals[] = {1, 2};
  int* a3 = a3_vals;
  int a3_len = 2;
  int r3 = leq(a3, a3_len, b, b_len);
  /*@ assert r3; */
  int a4_vals[] = {1, 1, 2};
  int* a4 = a4_vals;
  int a4_len = 3;
  int r4 = leq(a4, a4_len, b, b_len);
  /*@ assert ((a4[1] < b[1]) && r4); */
  int a5_vals[] = {1, 2, 3};
  int* a5 = a5_vals;
  int a5_len = 3;
  int r5 = leq(a5, a5_len, b, b_len);
  /*@ assert !(r5); */
  int a6_vals[] = {2};
  int* a6 = a6_vals;
  int a6_len = 1;
  int r6 = leq(a6, a6_len, b, b_len);
  /*@ assert !(r6); */
}