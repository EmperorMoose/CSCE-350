#ifndef BLOCKCHAIN_H_
#define BLOCKCHAIN_H_
#endif

#include "picosha2.h"
#include "block.h"
#include "blockchain.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

std::string nonceMiner(std::string xhead, std::string xmerk)
{
  bool found = false;
  while(found = false)
  {
    
  }
}

//generates a merkle root
std::string merkleGenerator(std::vector<std::string> transactionChain)
{
  //storing the strings from the input file and concatenating the first two lines
  std::string temp1 = transactionChain.at(0)+transactionChain.at(1)+transactionChain.at(2)+transactionChain.at(3);
  std::string temp2 = transactionChain.at(4)+transactionChain.at(5)+transactionChain.at(6)+transactionChain.at(7);
  std::string temp3 = transactionChain.at(8)+transactionChain.at(9)+transactionChain.at(10)+transactionChain.at(11);
  std::string temp4 = transactionChain.at(12)+transactionChain.at(13)+transactionChain.at(14)+transactionChain.at(15);

  //first round of hashing
  temp1 = picosha2::hash256_hex_string(temp1);
  temp2 = picosha2::hash256_hex_string(temp2);
  temp3 = picosha2::hash256_hex_string(temp3);
  temp4 = picosha2::hash256_hex_string(temp4);

  //Second round of concatenating
  temp1 = temp1 + temp2;
  temp3 = temp3 + temp4;

  //second round of hashing
  temp1 = picosha2::hash256_hex_string(temp1);
  temp3 = picosha2::hash256_hex_string(temp3);

  //final concatenation
  temp1 = temp1+temp3;

  //final hashing
  std::string merkle = picosha2::hash256_hex_string(temp1);
  return merkle;
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

  //This reads the transaction file into a vector
  std::ifstream file2(argv[2]);
  std::vector<std::string> transactionChain;
  std::string input_2;
  while(file2 >> input_2)
  {
    transactionChain.push_back(input_2);
  }
  //This is how object generation works
  //Generates the block objects
  block * block_1 = new block();
  block_1->setHeader(vecChain.at(0));
  block_1->setMerkle(vecChain.at(1));
  block_1->setNonce(vecChain.at(2));
  block_1->generateHash();
  block_1->isValid();

  block * block_2 = new block();
  block_2->setHeader(vecChain.at(3));
  block_2->setMerkle(vecChain.at(4));
  block_2->setNonce(vecChain.at(5));
  block_2->generateHash();
  block_2->isValid();

  block * block_3 = new block();
  block_3->setHeader(vecChain.at(6));
  block_3->setMerkle(vecChain.at(7));
  block_3->setNonce(vecChain.at(8));
  block_3->generateHash();
  block_3->isValid();

  //block_1->printBlock();
  //block_2->printBlock();
  //block_3->printBlock();
  //Prints the vector. For testing.
  //for (std::vector<std::string>::const_iterator i = vecChain.begin(); i != vecChain.end(); ++i)
    //std::cout << *i << ' ';

  //Check weather or not each block is valid.
  if(!block_1->validity || !block_2->validity || !block_3->validity)
  {
    //If not valid, print the merkle root
    std::string merkle = merkleGenerator(transactionChain);
    std::cout << "A block is invalid. Merkle Root: " << merkle << "\n";
  }
  blockchain * chain = new blockchain();
  if(!chain->chainValidity)
  {
    //If not valid, print the merkle root
    std::string merkle = merkleGenerator(transactionChain);
    std::cout << "The chain is invalid. Merkle Root: " << merkle << "\n";
  }
  //If valid make new block
  block * newBlock = new block();
  //make new header
  std::string newHeader = block_1->getHash();
  std::cout << newHeader << " ";
  newBlock->setHeader(newHeader);
  //make new merkle
  std::string newMerkle = merkleGenerator(transactionChain);
  newBlock->setMerkle(newMerkle);
  std::cout << newMerkle << " ";
  //Get nonce
  std::string newNonce = nonceMiner(newHeader, newMerkle);
  newBlock->setNonce(newNonce);
  std::cout << newNonce << " ";
  return 0;
}
