#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int convert_string_num_to_digit(string str_num)
{
  map<string, int> strings_map;
  strings_map["zero"] = 0;
  strings_map["one"] = 1;
  strings_map["two"] = 2;
  strings_map["three"] = 3;
  strings_map["four"] = 4;
  strings_map["five"] = 5;
  strings_map["six"] = 6;
  strings_map["seven"] = 7;
  strings_map["eight"] = 8;
  strings_map["nine"] = 9;

  if (strings_map.find(str_num) == strings_map.end())
  {
    return -1;
  }

  return strings_map[str_num];
}

string convert_line_with_str_nums_to_line_with_digits(string line)
{
  int digit_lengths[3] = {3, 4, 5};
  const int MAX_LENGTH = 5;
  const int MIN_LENGTH = 3;
  string line_copy = line.substr(0, line.length());
  if (line.length() < MAX_LENGTH)
  {
    return line;
  }
  for (int i = 0; i < line.length() - MAX_LENGTH; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      string str_num = line.substr(i, digit_lengths[j]);
      if (convert_string_num_to_digit(str_num) >= 0)
      {
        int result = convert_string_num_to_digit(str_num);
        string replace_with = to_string(result);
        line_copy.replace(i, digit_lengths[j], replace_with);
        break;
      }
    }
  }
  return line_copy;
}

int main()
{
  ifstream file("input.txt");
  string line;

  if (file.is_open())
  {
    while (getline(file, line))
    {
      cout << line << endl;
      cout << convert_line_with_str_nums_to_line_with_digits(line) << endl;
    }
    file.close();
  }
  else
  {
    cout << "Unable to open file";
  }
}