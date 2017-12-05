#include "block.h"
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
  void blockchain();
  void isValid();
  bool validity;
private:
  block::block block_1;
  block::block block_2;
  block::block block_3;
}
