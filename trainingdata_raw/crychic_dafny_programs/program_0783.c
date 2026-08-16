// Generated C + ACSL

/*@
    requires min >= 0;
    assigns \nothing;
    ensures \result == 1 <==> min <= max;
*/
int UpdateAmountRange(int min, int max)
{
  int success;
  if ((min <= max))
  {
    int amountMin = min;
    /*@ assert amountMin >= 0 && amountMin <= 2147483647; */
    int amountMax = max;
    /*@ assert amountMax >= 0 && amountMax <= 2147483647; */
    success = 1;
    /*@ assert success >= 0 && success <= 2147483647; */
  }
  else
  {
    success = 0;
  }
  return success;  // Dafny implicit return
}

/*@
    requires newTaux >= 0;
    assigns \nothing;
    ensures \result == 1 <==> newTaux <= 100;
*/
int UpdateTaux(int newTaux)
{
  int success;
  if ((newTaux <= 100))
  {
    int taux = newTaux;
    /*@ assert taux >= 0 && taux <= 2147483647; */
    success = 1;
    /*@ assert success >= 0 && success <= 2147483647; */
  }
  else
  {
    success = 0;
  }
  return success;  // Dafny implicit return
}