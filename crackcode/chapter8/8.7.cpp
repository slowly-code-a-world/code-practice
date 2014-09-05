/*
8.7 Explain how you would design a chat server. In particular, provide details about
   the various backend components, classes, and methods. What would be the
  hardest problems to solve?
*/

#include <iostream>

class chat_server {
private:
	string ip;
public:
	string get_ip() { return ip; }
};
