#include "../base/stuff.h"
#include <assert.h>
#include <stdio.h>
#include <vector>

void get_cpu_num_test() {
  int cpu = chef::stuff::get_cpu_num();
  (void)cpu;
}

void exe_test() {
  std::string filepath = chef::stuff::get_exe_filepath();
  std::string path = chef::stuff::get_exe_path();
  std::string name = chef::stuff::get_exe_name();
  assert(name == std::string("stuff_test"));
  (void)filepath;
  (void)path;
}

void readable_bytes_test() {
  assert(chef::stuff::readable_bytes(768) == "768.0B");
  assert(chef::stuff::readable_bytes(10000) == "9.8K");
  assert(chef::stuff::readable_bytes(100001221) == "95.4M");
  assert(chef::stuff::readable_bytes(1000) == "1000.0B");
  assert(chef::stuff::readable_bytes(1023) == "1023.0B");
  assert(chef::stuff::readable_bytes(1024) == "1.0K");
  assert(chef::stuff::readable_bytes(1025) == "1.0K");
  assert(chef::stuff::readable_bytes(1000UL * 1000) == "976.6K");
  assert(chef::stuff::readable_bytes(1024UL * 1024) == "1.0M");
  assert(chef::stuff::readable_bytes(1000UL * 1000 * 1000) == "953.7M");
  assert(chef::stuff::readable_bytes(1024UL * 1024 * 1024) == "1.0G");
  assert(chef::stuff::readable_bytes(1024UL * 1024 * 1024 + 1000UL * 1000 * 1000) == "1.9G");
  assert(chef::stuff::readable_bytes(1000UL * 1000 * 1000 * 1000) == "931.3G");
  assert(chef::stuff::readable_bytes(1024UL * 1024 * 1024 * 1024) == "1.0T");
  assert(chef::stuff::readable_bytes(1024UL * 1024 * 1024 * 1024 * 1024) == "1.0P");
  assert(chef::stuff::readable_bytes(1024UL * 1024 * 1024 * 1024 * 1024 * 1024) == "1.0E");
  assert(chef::stuff::readable_bytes(1024UL * 1024 * 1024 * 1024 * 1024 * 1024 * 15) == "15.0E");
  assert(chef::stuff::readable_bytes(0UL - 1) == "16.0E");
  assert(chef::stuff::readable_bytes(18446744073709551615UL) == "16.0E");
}

void get_host_by_name_test() {
  std::vector<std::string> domains = {
    "http://www.baidu.com/test?a=b",
    "http://www.baidu.com/test",
    "http://www.baidu.com/",
    "http://www.baidu.com",
    "www.baidu.com",
    "localhost",
    "not exist",
    "58.96.168.38"
  };
  for (auto iter : domains) {
    std::string ip = chef::stuff::get_host_by_name(iter);
    (void)ip;
    //printf("%s: %s\n", iter.c_str(), ip.c_str());
  }
}

void join_test() {
  std::string delimiter = "---";
  std::vector<std::string> array;
  assert(chef::stuff::join(array, delimiter) == std::string());
  array.push_back("test");
  assert(chef::stuff::join(array, delimiter) == std::string("test"));
  array.push_back("hello");
  assert(chef::stuff::join(array, delimiter) == std::string("test---hello"));
  array.push_back("world");
  assert(chef::stuff::join(array, delimiter) == std::string("test---hello---world"));
}

void split_test() {
  assert(chef::stuff::split(std::string(), '-').empty());
  std::string str1 = "a";
  std::vector<std::string> res1 = chef::stuff::split(str1, '-');
  assert(res1.size() == 1);
  assert(res1[0] == "a");

  std::string str2 = "a-";
  std::vector<std::string> res2 = chef::stuff::split(str2, '-');
  assert(res2.size() == 1);
  assert(res2[0] == "a");

  std::string str3 = "-a";
  std::vector<std::string> res3 = chef::stuff::split(str3, '-');
  assert(res3.size() == 1);
  assert(res3[0] == "a");

  std::string str4 = "a*bc";
  std::vector<std::string> res4 = chef::stuff::split(str4, '*');
  assert(res4.size() == 2);
  assert(res4[0] == "a");
  assert(res4[0] == "bc");

  std::string str5 = "--";
  std::vector<std::string> res5 = chef::stuff::split(str5, '-');
  assert(res5.size() == 0);
}

int main() {
  printf("Check stuff.\n");
  get_cpu_num_test();
  exe_test();
  readable_bytes_test();
  get_host_by_name_test();
  join_test();

  printf("Check stuff done.\n");
  return 0;
}
