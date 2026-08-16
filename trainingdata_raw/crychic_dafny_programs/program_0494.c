// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Reverse(int* a, int a_len);

void Test(void)
{
  int a_vals[] = {1, 2, 3, 4, 5};
  int* a = a_vals;
  int a_len = 5;
  //@ assert a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5;
  Reverse(a, a_len);
  //@ assert \forall integer i; 0 <= i < 5 ==> a[i] == (5 - i);
}

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i; 0 <= i < a_len ==> a[i] == \old(a[a_len - i - 1]);
*/
void Reverse(int* a, int a_len)
{
  int l = 0;
  int r = (a_len - 1);
/*@
  loop invariant 0 <= l <= (a_len + 1) / 2;
  loop invariant r == a_len - l - 1;
  loop invariant \forall integer i; 0 <= i < l ==> a[i] == \at(a[a_len - i - 1], LoopEntry);
  loop invariant \forall integer i; r < i < a_len ==> a[i] == \at(a[a_len - i - 1], LoopEntry);
  loop invariant \forall integer i; l <= i <= r ==> a[i] == \at(a[i], LoopEntry);
  loop assigns l, r, a[0..a_len-1];
  loop variant r - l;
*/
  while ((l < r))
    {
      int temp = a[l];
      a[l] = a[r];
      a[r] = temp;
      l = (l + 1);
      r = (r - 1);
    }
}