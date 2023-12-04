#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream file("input.txt");
  string num_str;
  string two_digit_num_str;
  int global_sum = 0;
  // END: ed8c6549bwf9

  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      num_str = "";
      for (int i = 0; i < line.length(); i++)
      {
        if (isdigit(line[i]))
        {
          num_str += line[i];
        }
      }
      two_digit_num_str = string() + num_str[0] + num_str[num_str.length() - 1];
      global_sum += stoi(two_digit_num_str);
    }
    file.close();
    cout << global_sum << endl;
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
}