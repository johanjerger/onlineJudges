#include <iostream>
#include <sstream>
#include <map>

using namespace std;

struct commit {
  int minutes;
  bool valid;
};

map<char, commit> final_result;

void resolve()
{
  int solved = 0, used_time = 0;

  for (std::map<char,commit>::iterator it = final_result.begin(); it != final_result.end(); ++it){
    if(it->second.valid){
      solved++;
      used_time += it->second.minutes;
    }
  }

  cout << solved << ' ' << used_time << endl;
}

void store(int minute, char problem, bool result)
{
  int final_time, time_value;

  time_value = (result) ? minute : 20;

  map<char,commit>::iterator it = final_result.find(problem);
  if (it != final_result.end()){
    final_time = time_value + final_result.at(problem).minutes;
  } else {
    final_time = time_value;
  }

  struct commit new_commit = {
    final_time,
    result
  };

  if ( it != final_result.end() ) {
    final_result.at(problem) = new_commit;
  } else {
    final_result.insert( std::pair<char, commit>(problem, new_commit) );
  }
}

int main()
{
  int minute;
  char problem;
  string result,  input;

  while (getline(std::cin, input) && !input.empty()) {
      stringstream ss(input.c_str());
      if(ss >> minute && minute == -1){
        resolve();
        final_result.clear();
      } else {
        ss >> problem >> result;
        store(minute, problem, result == "right" ? true : false);
      }
  }

  return 0;
}
