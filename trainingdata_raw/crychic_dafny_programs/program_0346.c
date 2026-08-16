// Generated C + ACSL

void Replace(int* a, int a_len, int oldval, int newval);

/*@
    assigns \nothing;
*/
void Test(void)
{
  int a_vals[] = {2, 8, 6, 5, 2, 2, 7, 4, 1};
  int* a = a_vals;
  int a_len = 9;
  /*@ assert \forall integer i; 0 <= i < 9 ==>
        a[i] == \at(a_vals[i], Here); */
  Replace(a, a_len, 2, 7);
  /*@ assert a[0] == 7 && a[1] == 8 && a[2] == 6 && a[3] == 5 &&
             a[4] == 7 && a[5] == 7 && a[6] == 7 && a[7] == 4 && a[8] == 1; */
}

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i; 0 <= i < a_len ==>
        (\old(a[i]) == oldval ==> a[i] == newval);
    ensures \forall integer i; 0 <= i < a_len ==>
        (\old(a[i]) != oldval ==> a[i] == \old(a[i]));
*/
void Replace(int* a, int a_len, int oldval, int newval)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; i <= j < a_len ==> a[j] == \at(a[j], LoopEntry);
  loop invariant \forall integer j; 0 <= j < i ==> (\at(a[j], LoopEntry) == oldval ==> a[j] == newval);
  loop invariant \forall integer j; 0 <= j < i ==> (\at(a[j], LoopEntry) != oldval ==> a[j] == \at(a[j], LoopEntry));
  loop assigns i, a[0..a_len-1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] == oldval))
      {
        a[i] = newval;
      }
      i = (i + 1);
    }
}