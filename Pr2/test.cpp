#include "picosha2.h"
#include "block.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

int hexCharToInt(char a){
    if(a>='0' && a<='9')
        return(a-48);
    else if(a>='A' && a<='Z')
        return(a-55);
    else
        return(a-87);
}

std::string hexToString(std::string str){
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

int main(int argc, char* argv[])
{
  //Original contents of main preserved for clarity
  //std::string hex_str = "000000000000000000ad6e90c0790e83760a9d13728c23474352a2c8c7a6e0eb";
  //std::cout << picosha2::hash256_hex_string(hexToString(hex_str)) << std::endl;

  //This block reads in from the file into a vector
  std::ifstream file(argv[1]);
  std::vector<std::string> vecChain;
  std::string input;
  while(file >> input)
  {
    vecChain.push_back(input);
  }

  //these are the vectors for each block in the input file.
  std::vector<std::string> vecBlock_1;
  std::vector<std::string> vecBlock_2;
  std::vector<std::string> vecBlock_3;

  for(int i=0;i<vecChain.size();i++)


  //Prints the vector. For testing.
  for (std::vector<std::string>::const_iterator i = vecChain.begin(); i != vecChain.end(); ++i)
    std::cout << *i << ' ';


  //std::string chain = header + merkle + nonce;

  //bool validity = isValid(chain);
  bool validity = true;
  if(validity == true)
  {
    std::cout << "true";
  }
  else
  {
    std::cout << "false";
  }
  return 0;
}
