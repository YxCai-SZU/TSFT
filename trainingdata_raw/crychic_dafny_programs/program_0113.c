// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \exists integer k; 0 <= k < a_len && \result == a[k];
    ensures \forall integer k; 0 <= k < a_len ==> \result >= a[k];
*/
int findMax(int* a, int a_len)
{
  int max = a[0];
  /*@ assert max == a[0]; */
  /*@ assert \exists integer k; 0 <= k < 1 && max == a[k]; */
  /*@ assert \forall integer k; 0 <= k < 1 ==> max >= a[k]; */
  {
    int i = 1;
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant \exists integer k; 0 <= k < i && max == a[k];
  loop invariant \forall integer k; 0 <= k < i ==> max >= a[k];
  loop assigns i, max;
  loop variant a_len - i;
*/
    while ((i < a_len))
      {
        if ((a[i] > max))
        {
          max = a[i];
          /*@ assert max == a[i]; */
        }
        /*@ assert max >= a[i]; */
        i = (i + 1);
      }
    /*@ assert i == a_len; */
    /*@ assert \exists integer k; 0 <= k < a_len && max == a[k]; */
    /*@ assert \forall integer k; 0 <= k < a_len ==> max >= a[k]; */
  }
  return max;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void testFindMax(void)
{
  int a1[] = {1, 2, 3};
  int m1 = findMax(a1, 3);
  /*@ assert m1 == a1[2] == 3.0; */
  int a2[] = {3, 2, 1};
  int m2 = findMax(a2, 3);
  /*@ assert m2 == a2[0] == 3.0; */
  int a3[] = {2, 3, 1};
  int m3 = findMax(a3, 3);
  /*@ assert m3 == a3[1] == 3.0; */
  int a4[] = {1, 2, 2};
  int m4 = findMax(a4, 3);
  /*@ assert m4 == a4[1] == 2.0; */
  int a5[] = {1};
  int m5 = findMax(a5, 1);
  /*@ assert m5 == a5[0] == 1.0; */
  int a6[] = {1, 1, 1};
  int m6 = findMax(a6, 3);
  /*@ assert m6 == a6[0] == 1.0; */
}