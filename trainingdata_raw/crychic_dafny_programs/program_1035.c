// Generated C + ACSL

/*@
    requires request != 0;
    assigns \nothing;
    ensures \result != 0;
*/
int GetCartFromRequest(int request)
{
  int cart = 0;
  if (request != 0)
  {
    cart = request;
    /*@ assert cart != 0; */
  }
  else
  {
    cart = 0;
  }
  return cart;
}