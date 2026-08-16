// Generated C + ACSL

/*@
    requires costPrice >= 0;
    requires sellingPrice >= 0;
    assigns \nothing;
    ensures (costPrice > sellingPrice ==> \result == costPrice - sellingPrice);
    ensures (costPrice <= sellingPrice ==> \result == 0);
*/
int CalculateLoss(int costPrice, int sellingPrice)
{
  int loss;
  if ((costPrice > sellingPrice))
  {
    loss = (costPrice - sellingPrice);
    /*@ assert loss >= 0 && loss <= 2147483647; */
  }
  else
  {
    loss = 0;
  }
  return loss;  // Dafny implicit return
}