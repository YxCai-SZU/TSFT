// Generated C + ACSL

/*@
    requires num >= 0 && num <= a_len - 1;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. num];
    ensures \forall integer i; 0 <= i <= num ==>
        a[i] == \old(a[num - i]) && a[num - i] == \old(a[i]);
    ensures \forall integer i; num < i <= a_len - 1 ==>
        a[i] == \old(a[i]);
*/
void flip(int* a, int a_len, int num)
{
  int tmp;
  int i = 0;
  int j = num;
/*@
  loop invariant 0 <= i <= num;
  loop invariant 0 <= j <= num;
  loop invariant i + j == num;
  loop invariant \forall integer z; i <= z <= j ==> a[z] == \at(a[z], LoopEntry);
  loop invariant \forall integer z; (0 <= z < i || j < z <= num) ==>
                   (a[num - z] == \at(a[z], LoopEntry) && a[z] == \at(a[num - z], LoopEntry));
  loop invariant \forall integer z; num < z < a_len ==> a[z] == \at(a[z], LoopEntry);
  loop assigns i, j, tmp, a[0..num];
  loop variant j - i;
*/
  while ((i < j))
    {
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i = (i + 1);
      j = (j - 1);
    }
}