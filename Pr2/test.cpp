#include "picosha2.h"
#include "blockchain.h"
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

  //Generates the block objects
  block::block block_1 = new block();
  block_1.setHeader(vecChain.at(0));
  block_1.setMerkle(vecChain.at(1));
  block_1.setNonce(vecChain.at(2));

  block::block block_2 = new block();
  block_2.setHeader(vecChain.at(3));
  block_2.setMerkle(vecChain.at(4));
  block_2.setNonce(vecChain.at(5));

  block::block block_3 = new block();
  block_3.setHeader(vecChain.at(6));
  block_3.setMerkle(vecChain.at(7));
  block_3.setNonce(vecChain.at(8));

  //Prints the vector. For testing.
  for (std::vector<std::string>::const_iterator i = vecChain.begin(); i != vecChain.end(); ++i)
    std::cout << *i << ' ';

  //Check weather or not each block is valid.
  if(!block_1.validity || !block_2.validity || !block_3.validity)
  {
    //TODO Add the invalid output
  }
  blockchain::blockchain blockchain = new blockchain(block_1,block_2,block_3);
  if(!blockchain.validity)
  {
    //TODO Add the invalid output
  }
  return 0;
}
