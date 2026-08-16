// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0 && \result <= 3;
    ensures \result == 3 <==> (a == b && b == c);
    ensures \result == 2 <==> ((a == b && b != c) || (a != b && b == c) || (a == c && b != c));
    ensures \result == 1 <==> (a != b && b != c && a != c);
*/
int CountEqualNumbers(int a, int b, int c)
{
  int count = 1;
  /*@ assert count >= 0 && count <= 2147483647; */
  if ((a == b))
  {
    count = (count + 1);
  }
  if ((a == c))
  {
    count = (count + 1);
  }
  if (((a != b) && (b == c)))
  {
    count = (count + 1);
  }
  return count;  // Dafny implicit return
}
