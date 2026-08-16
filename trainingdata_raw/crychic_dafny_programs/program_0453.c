// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
*/
void XCDE(void)
{
  int UFOT = 0;
  int QWIK = 0;
/*@
  loop invariant \at(UFOT, LoopEntry) <= UFOT <= 33;
  loop invariant QWIK == UFOT * (UFOT + 1) / 2;
  loop invariant UFOT >= 0;
  loop invariant QWIK >= 0;
  loop invariant QWIK <= 2147483647;
  loop invariant UFOT <= 2147483647;
  loop assigns UFOT, QWIK;
  loop variant 33 - UFOT;
*/
  while ((UFOT != 33))
    {
      UFOT = (UFOT + 1);
      /*@ assert UFOT >= 0 && UFOT <= 2147483647; */
      QWIK = (QWIK + UFOT);
      /*@ assert QWIK >= 0 && QWIK <= 2147483647; */
    }
}