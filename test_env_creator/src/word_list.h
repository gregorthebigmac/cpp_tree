#ifndef WORD_LIST_HPP
#define WORD_LIST_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

class word_list {
public:
	word_list() {
		srand(time(NULL));
		std::vector<std::string> _words;
		std::string _filename;
		std::ifstream fin;
		fin.open("words.txt");
		if (fin.is_open()) {
			while (!fin.eof()) {
				std::string _temp;
				std::getline(fin, _temp);
				_words.push_back(_temp);
			}
			fin.close();
		}
		else std::cout << "fin: ERROR: failed to open \"words.txt\"!" << std::endl;
	}
	
	~word_list() {}
	
	std::string get_random_word() {
		int _rand_word_pos = rand() % m_word_list.size();
		std::string _rand_word = m_word_list[_rand_word_pos];
		if (_rand_word != "")
			return _rand_word;
		else return "bad_filename";
	}
	
private:
	std::vector<std::string> m_word_list;
};

#endif
