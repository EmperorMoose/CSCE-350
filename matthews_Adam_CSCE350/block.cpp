#include "block.h"
#include "picosha2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
//This is the function file for the block class
block::block()
{
  generateHash();
  isValid();
}
//This is a function from test.cpp
int block::hexCharToInt(char a){
    if(a>='0' && a<='9')
        return(a-48);
    else if(a>='A' && a<='Z')
        return(a-55);
    else
        return(a-87);
}

//Function from test.cpp
std::string block::hexToString(std::string str){
    std::stringstream HexString;
    for(int i=0;i<str.length();i++){
        char a = str.at(i++);
        char b = str.at(i);
        int x = hexCharToInt(a);
        int y = hexCharToInt(b);
        HexString << (char)((16*x)+y);
    }
    return HexString.str();
}
//----------------------------------------------------------------------------//
//Checks whether or not a chain is valid by looking at the first bit in the hash
void block::isValid()
{
  if(hash.at(0) ==  '0')
  {
    validity = true;
  }
  else
  {
    validity = false;
  }
}

//Setters
void block::setHeader(std::string x)
{
  header = x;
}

void block::setMerkle(std::string y)
{
  merkle = y;
}

void block::setNonce(std::string z)
{
  nonce = z;
}

//getter
std::string block::getHeader()
{
  return header;
}
//Generates the hash value for this blockchain
void block::generateHash()
{
  std::string concat = header + merkle + nonce;
  hash = picosha2::hash256_hex_string(hexToString(concat));
}

//getter
std::string block::getHash()
{
  return hash;
}

//Print the block. For testing.
void block::printBlock()
{
  std::cout << block::header << " ";
  std::cout << merkle << " ";
  std::cout << nonce << "\n";
}
