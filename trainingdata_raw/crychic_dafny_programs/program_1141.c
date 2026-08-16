// Generated C + ACSL

/*@
    requires sayi >= 0;
    assigns \nothing;
    ensures \result == ((sayi / 10 % 10 > 3) && (sayi / 10 % 10 < 7));
*/
int OnlarBasamagi(int sayi)
{
  int tens = ((sayi / 10) % 10);
  if (((tens > 3) && (tens < 7)))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}