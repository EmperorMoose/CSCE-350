#include "block.h"
#include "blockchain.h"
#include "picosha2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

//Constructor
void blockchain::blockchain(block::block block_1, block::block block_2, block::block block_3)
{
  block_1 = block_1;
  block_2 = block_2;
  block_3 = block_3;
  isValid();
}

//Checks wether or not the chain is valid
void blockchain::isValid()
{
    if(block_1.getHeader() == block_2.getHash())
    {
      if(block_2.getHeader() == block_3.getHash())
        validity = true;
      else
        validity = false;
    }
    else
      validity = false;
}
