// Generated C + ACSL

/*@
    requires msg != \null;
    requires prefix != \null;
    requires msg_len >= 0;
    requires prefix_len >= 0;
    requires \valid_read(msg + (0 .. msg_len-1));
    requires \valid_read(prefix + (0 .. prefix_len-1));
    requires clients_len >= 0;
    assigns \nothing;
*/
void Broadcast(char* msg, int msg_len, char* prefix, int prefix_len, int clients_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= clients_len;
  loop assigns i;
  loop variant clients_len - i;
*/
  while ((i < clients_len))
    {
      /* unsupported stmt: print "Sending message to client ", clients[i].name, ": ", prefix + msg; */
      i = (i + 1);
    }
}