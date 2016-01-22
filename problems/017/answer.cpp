#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

int main(){
  map<string, string> m;

  m.insert(pair<string,string> ("0", ""         ));

  m.insert(pair<string,string> ("1", "one"      ));
  m.insert(pair<string,string> ("2", "two"      ));
  m.insert(pair<string,string> ("3", "three"    ));
  m.insert(pair<string,string> ("4", "four"     ));
  m.insert(pair<string,string> ("5", "five"     ));
  m.insert(pair<string,string> ("6", "six"      ));
  m.insert(pair<string,string> ("7", "seven"    ));
  m.insert(pair<string,string> ("8", "eight"    ));
  m.insert(pair<string,string> ("9", "nine"     ));

  m.insert(pair<string,string> ("10", "ten"     ));
  m.insert(pair<string,string> ("11", "eleven"  ));
  m.insert(pair<string,string> ("12", "twelve"  ));
  m.insert(pair<string,string> ("13", "thirteen"));
  m.insert(pair<string,string> ("14", "fourteen" ));
  m.insert(pair<string,string> ("15", "fifteen" ));
  m.insert(pair<string,string> ("16", "sixteen" ));
  m.insert(pair<string,string> ("17", "seventeen"));
  m.insert(pair<string,string> ("18", "eighteen" ));
  m.insert(pair<string,string> ("19", "nineteen" ));

  m.insert(pair<string,string> ("20", "twenty"  ));
  m.insert(pair<string,string> ("30", "thrity"  ));
  m.insert(pair<string,string> ("40", "forty"   ));
  m.insert(pair<string,string> ("50", "fifty"   ));
  m.insert(pair<string,string> ("60", "sixty"   ));
  m.insert(pair<string,string> ("70", "seventy" ));
  m.insert(pair<string,string> ("80", "eighty"  ));
  m.insert(pair<string,string> ("90", "ninety"   ));

  m.insert(pair<string,string> ("h", "hundred"  ));

  m.insert(pair<string,string> ("th", "thousand"));

  cout << "========== C++ ==========" << endl;

  int s_1_9 = 0;
  for (int i = 1; i < 10; i++){
    s_1_9 += m[to_string(i)].length();
  }
  cout << "1-9 sum: " << s_1_9 << endl;
  // sum += s_1_9;

  int s_10_19 = 0;
  for (int i = 10; i < 20; i++){
    s_10_19 += m[to_string(i)].length();
  }
  cout << "10-19 sum: " << s_10_19 << endl;
  // sum += s_10_19;

  int s_20_99 = 0;
  for (int i = 20; i < 100; i++){
    s_20_99 += m[to_string(i%100 - i%10)].length();
    s_20_99 += m[to_string(i%10)].length();
  }
  cout << "20-99 sum: " << s_20_99 << endl;
  // sum += s_20_99;

  int s_100_999_a = 0;
  for (int i = 1; i < 100; i++){
    s_100_999_a += m["h"].length() + 3; // for and
  }
  s_100_999_a = 9 * s_100_999_a;
  cout << "100-999_a sum: " << s_100_999_a << endl;

  int sum = 100 * s_1_9 + 10 * (s_1_9 + s_10_19 + s_20_99) + 9 * m["h"].length() + s_100_999_a + m["1"].length() + m["th"].length();
  cout << "sum: " << sum << endl << "=========================" << endl;

}
