// Generated C + ACSL

/*@
    requires numelems > 0;
    requires a != \null;
    requires a_len >= numelems;
    requires \valid(a + (0 .. numelems-1));
    assigns \nothing;
    ensures \forall integer j; 0 <= j < numelems ==> \result >= a[j];
    ensures \exists integer j; 0 <= j < numelems && \result == a[j];
*/
int max(int* a, int a_len, int numelems)
{
  int i = 1;
  int r = a[0];
  /*@ assert \exists integer k; 0 <= k < 1 && r == a[k]; */
  /*@ assert r == a[0]; */
/*@
  loop invariant 1 <= i <= numelems;
  loop invariant \forall integer j; 0 <= j < i ==> r >= a[j];
  loop invariant \exists integer j; 0 <= j < i && r == a[j];
  loop invariant r == a[0] || (\exists integer k; 1 <= k < i && r == a[k]);
  loop assigns i, r;
  loop variant numelems - i;
*/
  while ((i < numelems))
    {
      if ((a[i] > r))
      {
        r = a[i];
        /*@ assert r == a[i]; */
      }
      /*@ assert r >= a[i]; */
      /*@ assert \exists integer k; 0 <= k < i+1 && r == a[k]; */
      i = (i + 1);
    }
  /*@ assert i == numelems; */
  /*@ assert \exists integer j; 0 <= j < numelems && r == a[j]; */
  /*@ assert \forall integer j; 0 <= j < numelems ==> r >= a[j]; */
  return r;  // Dafny implicit return
}