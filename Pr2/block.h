//This is the header file for the block class
#include "picosha2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

class block{
public:
  block();
  void isValid();
  bool validity;
  void setHeader(std::string header);
  void setMerkle(std::string merkle);
  void setNonce(std::string nonce);
  std::string getHeader();
  std::string getHash();
  void generateHash();
  std::string hexToString(std::string str);
  int hexCharToInt(char a);
  void printBlock();
private:
  std::string header;
  std::string merkle;
  std::string nonce;
  std::string hash;
};
