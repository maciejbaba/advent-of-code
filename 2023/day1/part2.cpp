#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream file("input.txt");
  struct strings_map
  {
    string zero = "0";
    string one = "1";
    string two = "2";
    string three = "3";
    string four = "4";
    string five = "5";
    string six = "6";
    string seven = "7";
    string eight = "8";
    string nine = "9";
  };
  string strings[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  int lengths[10] = {3, 4, 5};
  string digit_str = "";
  string num_str = "";
  int global_sum;

  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      digit_str = "";
      num_str = "";
      cout << line << endl;
      for (int i = 0; i < line.length() - 5; i++)
      {
        for (int j = 0; j < sizeof(lengths); j++)
        {
          string temp = line.substr(i, lengths[j]);
          if (temp == strings[j])
          {
            line = line.replace(i, lengths[j], strings_map().temp);
            i += lengths[j] - 1;
          }
        }
      }
      cout << line << endl;
      for (int i = 0; i < 10; i++)
      {
        if (line.find(strings[i]) != string::npos)
        {
          line = line.replace(line.find(strings[i]), strings[i].length(), to_string(i));
        }
      }
      cout << line << endl;
      for (int i = 0; i < line.length(); i++)
      {
        if (isdigit(line[i]))
        {
          digit_str += line[i];
        }
      }
      num_str = string() + digit_str[0] + digit_str[digit_str.length() - 1];
      cout << num_str << endl;
      global_sum += stoi(num_str);
    }
    file.close();
    cout << global_sum << endl;
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
}