// Generated C + ACSL

/*@
    requires a != \null && b != \null;
    requires a_len == b_len;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \valid_read(b + (0 .. b_len-1));
    requires \forall integer i; 0 <= i < a_len - 1 ==> a[i] <= a[i + 1];
    requires \forall integer i; 0 <= i < b_len - 1 ==> b[i] <= b[i + 1];
    requires \forall integer i; 0 <= i < a_len ==> a[i] >= 0;
    requires \forall integer i; 0 <= i < b_len ==> b[i] >= 0;
    requires \forall integer i; 0 <= i < a_len ==> a[i] <= 1073741823;
    requires \forall integer i; 0 <= i < b_len ==> b[i] <= 1073741823;
    assigns \nothing;
    ensures \result == (a_len % 2 == 0 ? (a[a_len / 2 - 1] + b[0]) / 2 : a[a_len / 2]);
*/
int FindMedian(int* a, int a_len, int* b, int b_len)
{
  int median;
  if (((a_len % 2) == 0))
  {
    /*@ assert 0 <= a_len / 2 - 1 < a_len; */
    /*@ assert 0 <= b[0] <= 1073741823; */
    /*@ assert 0 <= a[a_len / 2 - 1] <= 1073741823; */
    /*@ assert a[a_len / 2 - 1] + b[0] <= 2147483646; */
    median = ((a[((a_len / 2) - 1)] + b[0]) / 2);
    /*@ assert median >= 0 && median <= 2147483647; */
  }
  else
  {
    median = a[(a_len / 2)];
  }
  return median;  // Dafny implicit return
}