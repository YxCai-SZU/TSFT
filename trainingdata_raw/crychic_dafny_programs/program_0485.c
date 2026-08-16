// Generated C + ACSL

/*@
    requires i >= 0;
    assigns \nothing;
    ensures \result == i;
*/
int loop(int i)
{
  int z = 0;
  /*@ assert z >= 0 && z <= 2147483647; */
/*@
  loop invariant z <= i;
  loop invariant z >= \at(z, LoopEntry);
  loop assigns z;
  loop variant i - z;
*/
  while ((z < i))
    {
      z = (z + 1);
    }
  return z;  // Dafny implicit return
}
