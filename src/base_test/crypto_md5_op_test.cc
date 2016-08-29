#include "../base/crypto_md5_op.hpp"
#include <map>
#include <string>
#include <assert.h>

int main() {
  printf("Check crypto_md5.\n");
  std::map<std::string, std::string> mapping;
  mapping["d41d8cd98f00b204e9800998ecf8427e"] = "";
  mapping["0cc175b9c0f1b6a831c399e269772661"] = "a";
  mapping["ab56b4d92b40713acc5af89985d4b786"] = "abcde";
  mapping["a925576942e94b2ef57a066101b48876"] = "abcdefghij";
  mapping["de3a4d2fd6c73ec2db2abad23b444281"] = "There is no reason for any individual to have a computer in their home. -Ken Olsen, 1977";

  for (auto &iter : mapping) {
    assert(chef::md5_hash_hex(iter.second) == iter.first);
  }

  printf("Check crypto_md5 done.\n");
  return 0;
}