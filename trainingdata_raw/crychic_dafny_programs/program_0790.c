// Generated C + ACSL

// Global declarations
int hosts[1000];
int hosts_count = 0;
int credentials[1000];
int credentials_len = 0;

/*@
    requires host != 0;
    requires \valid(&hosts_count);
    requires 0 <= hosts_count < 1000;
    requires \valid(hosts + (0 .. hosts_count));
    assigns hosts[hosts_count], hosts_count;
    ensures hosts_count == \old(hosts_count) + 1;
    ensures hosts[\old(hosts_count)] == host;
    ensures \forall integer i; 0 <= i < \old(hosts_count) ==> hosts[i] == \old(hosts[i]);
*/
void AddHost(int host)
{
  hosts[hosts_count] = host;
  hosts_count = hosts_count + 1;
  /*@ assert hosts_count >= 0 && hosts_count <= 1000; */
}

/*@
    requires cred != 0;
    requires \valid(&credentials_len);
    requires 0 <= credentials_len < 1000;
    requires \valid(credentials + (0 .. credentials_len));
    assigns credentials[credentials_len], credentials_len;
    ensures credentials_len == \old(credentials_len) + 1;
    ensures credentials[\old(credentials_len)] == cred;
    ensures \forall integer i; 0 <= i < \old(credentials_len) ==>
            credentials[i] == \old(credentials[i]);
*/
void AddCredential(int cred)
{
  credentials[credentials_len] = cred;
  credentials_len = credentials_len + 1;
  /*@ assert credentials_len >= 0 && credentials_len <= 1000; */
}