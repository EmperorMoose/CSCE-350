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
#include <cstdlib>
#include <iomanip>

//This mines a new nonce. Takes in a string header and merkle
std::string nonceMiner(std::string xhead, std::string xmerk)
{
  //Decalre vars
  bool found = false;
  int rando;
  //Concat the head and merk for simplicity
  std::string concat = xhead + xmerk;
  std::string hash;
  std:: string result;
  //Looping condition
  while(found == false)
  {
    //generate random integer and convert to hex string
    rando = rand() % 99999999;
    std::stringstream sstream;
    sstream << std::hex << rand;
    result = sstream.str();

    //Add the nonce to the block
    concat = concat + result;
    hash = picosha2::hash256_hex_string(concat);
    //check if the hash is valid
    if(hash.at(0) == '0')
    {
      found = true;
    }
  }
  //Return the nonce
  return result;
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
  //This block reads in from the bitcoin file into a vector
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

  //Check weather or not each block is valid.
  if(!block_1->validity || !block_2->validity || !block_3->validity)
  {
    //If not valid, print the merkle root
    std::string merkle = merkleGenerator(transactionChain);
    std::cout << "A block is invalid. Merkle Root: " << merkle << "\n";
  }
  //Decalre the chain and check validity
  blockchain * chain = new blockchain();
  if(chain->chainValidity == true)
  {
    //If not valid, print the merkle root
    std::string merkle = merkleGenerator(transactionChain);
    std::cout << "The chain is invalid. Merkle Root: " << merkle << "\n";
  }
  //If valid make new block
  std::cout << "The chain is valid. New block is: \n";
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
  //This formats the nonce to include leading zeros
  if(newNonce.length() < 7)
  {
    std::string zeros;
    int size = 8 - newNonce.length();
    for(int i = 0; i< size; i++)
      zeros += '0';
    zeros = zeros + newNonce;
    std::cout << zeros + "\n";
    newBlock->setNonce(zeros);
  }
  return 0;
}
