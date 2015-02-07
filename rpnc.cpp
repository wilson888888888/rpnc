#include <iostream>
#include <queue>
#include <sstream>
#include <regex>
#include <math.h>
#include <stdlib.h>
std::queue<double> nums;
double E = 2.718281828459045;
double PI = 3.14159265358979;
double ans = 0;

void operate (std::string opr){
  double a = nums.front();
  nums.pop();
  double b = nums.front();
  nums.pop();
  if (opr == "+")
    nums.push(a + b);
  else if (opr == "-")
    nums.push(a - b);
  else if (opr == "*")
    nums.push(a * b);
  else if (opr == "/")
    nums.push(a / b);
  else if (opr == "^")
    nums.push(pow (a, b));
  else if (opr == "log")
    nums.push(log(a) / log(b));
  else if (opr == "sin"){
    nums.push(b);
    nums.push(sin(a));
  }
  else if (opr == "cos"){
    nums.push(b);
    nums.push(cos(a));
  }
  else if (opr == "tan"){
    nums.push(b);
    nums.push(tan(a));
  }
  else if (opr == "csc"){
    nums.push(b);
    nums.push(1 / sin(a));
  }
  else if (opr == "sec"){
    nums.push(b);
    nums.push(1 / cos(a));
  }
  else if (opr == "cot"){
    nums.push(b);
    nums.push(1 / tan(a));
  }
  else if (opr == "asin"){
    nums.push(b);
    nums.push(asin(a));
  }
  else if (opr == "acos"){
    nums.push(b);
    nums.push(acos(a));
  }
  else if (opr == "atan"){
    nums.push(b);
    nums.push(atan(a));
  }
  else if (opr == "abs"){
    nums.push(b);
    nums.push(abs(a));
  }
  else{
    std::cout << "Wrong syntax" << '\n';
    exit (EXIT_FAILURE);
  }
}

double calculate(std::string in){
  std::string s;
  std::istringstream instr;
  instr.str(in);
  while (getline(instr, s, ' ')){
    if (std::regex_match(s, std::regex("-?[0123456789]+[.]?[0123456789]*"))){
      nums.push(atof(s.c_str()));
    }
    else if (s == "e"){
      nums.push(E);
    }
    else if (s == "pi"){
      nums.push(PI);
    }
    else if (s == "ans"){
      nums.push(ans);
    }
    else{
      operate(s);
    }
  }
  double sol = nums.front();
  nums.pop();
  if (nums.empty())
    return sol;
  else{
    std::cout << "Invalid expression" << '\n';
    while (!nums.empty()){
      std::cout << nums.front() << '\n';
      nums.pop();
    }
    return 0;
  }
}

int main(){
  while (true){
    std::string in;
    std::cout << "Enter expression to evaluate" << '\n';
    getline(std::cin, in);
    ans = calculate(in);
    std::cout << ans << '\n';
  }
}
