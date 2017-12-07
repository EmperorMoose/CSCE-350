//#include "block.h"
#include "picosha2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

class blockchain{
public:
  blockchain();
  blockchain(block &block_1, block &block_2, block &block_3);
  void isChainValid();
  bool chainValidity;
  block * block_1;
  block * block_2;
  block * block_3;
};
