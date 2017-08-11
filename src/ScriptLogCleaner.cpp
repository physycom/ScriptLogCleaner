/******************************************************************************
Copyright 2015-2017 Stefano Sinigardi
The program is distributed under the terms of the GNU General Public License
******************************************************************************/

/**************************************************************************
This file is part of "ScriptLogCleaner".

ScriptLogCleaner is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ScriptLogCleaner is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ScriptLogCleaner.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/



#define ORIGINAL_COMMA_SEPARATION_VALUES ";"
//#define ORIGINAL_COMMA_SEPARATION_VALUES "\t ,;:"
#define COMMA_SEPARATION_VALUE ';'
#define TOKEN_GOOD_NUMBER 21
#define FIRST_GOOD_TOKEN "Index"

#include <iostream>
#include <fstream>
#include <vector>

#include <boost/utility.hpp>
#include <boost/algorithm/string.hpp>



void write_tokens(std::string file_name, std::vector< std::vector<std::string> > &file_tokens) {
  std::ofstream data_file;
  if (file_name.size()) data_file.open(file_name.c_str());
  else std::cout << "No filename defined" << std::endl;
  if (!data_file) {
    std::cout << "Failure: file " << file_name << " could not be opened. Press a key to exit." << std::endl;
    std::cin.get();
    exit(-1);
  }
  else {
    std::cout << "SUCCESS: file " << file_name << " opened!" << std::endl;
  }


  for (auto i : file_tokens) {
    for (auto j : i) data_file << j << (j != i.back() ? COMMA_SEPARATION_VALUE : ' ');
    data_file << std::endl;
  }

  data_file.close();
}


std::vector< std::vector<std::string> > tokenize(std::string file_name) {
  std::string line;
  std::vector<std::string> tokens;
  std::vector< std::vector<std::string> > file_tokens;
  bool found = false;
  std::ifstream data_file;
  if (file_name.size()) data_file.open(file_name.c_str());
  else std::cout << "No filename defined" << std::endl;
  if (!data_file) {
    std::cout << "Failure: file " << file_name << " could not be opened. Press a key to exit." << std::endl;
    std::cin.get();
    exit(-1);
  }
  else {
    std::cout << "SUCCESS: file " << file_name << " opened!" << std::endl;
  }

  while (!data_file.eof()){
    line.clear();
    tokens.clear();
    std::getline(data_file, line);
    boost::algorithm::trim(line);
    if (line.size()){
      boost::algorithm::split(tokens, line, boost::algorithm::is_any_of(ORIGINAL_COMMA_SEPARATION_VALUES));
      if (tokens[0] == FIRST_GOOD_TOKEN) found = true;
      if (tokens.size() == TOKEN_GOOD_NUMBER && found) {
        file_tokens.push_back(tokens);
      }
    }
  }

  data_file.close();
  return file_tokens;
}


int main(int argc, const char*argv[]) {
  std::string filename_in, filename_out;
  if (argc > 1) if (std::string(argv[1]).size()) filename_in = argv[1];
  if (argc > 2) if (std::string(argv[2]).size()) filename_out = argv[2];

  if (!filename_in.size())  {
    std::cout << "Insert filename_in: ";
    std::cin >> filename_in;
  }
  if (!filename_out.size())  {
    std::cout << "Insert filename_out: ";
    std::cin >> filename_out;
  }
  std::vector< std::vector<std::string> > file_tokens = tokenize(filename_in);
  write_tokens(filename_out, file_tokens);
  return 0;
}


