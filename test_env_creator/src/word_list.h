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
		std::string _filename;
		std::ifstream fin;
		fin.open("resources/words.txt");
		if (fin.is_open()) {
			while (!fin.eof()) {
				std::string _temp;
				std::getline(fin, _temp);
				m_word_list.push_back(_temp);
			}
			fin.close();
		}
		else std::cout << "fin: ERROR: failed to open \"words.txt\"!" << std::endl;
	}

	~word_list() {}

	std::string get_random_word() {
		//srand(time(NULL));
		//int _rand_word_pos = rand() % m_word_list.size();
		//std::string _rand_word = m_word_list[_rand_word_pos];
		//if (_rand_word != "")
			//return _rand_word;
		//else return "bad_filename";
		std::string _temp_word = m_word_list[m_word_list.size()];
		m_word_list.pop_back();
	}

	void randomize_words() {
		std::vector<std::string> _temp_words;
		for (int i = 0; i < m_word_list.size(); i++) {
			srand(time(NULL));
			int _rand_word_pos = rand() % m_word_list.size();
			std::string temp_word = m_word_list[_rand_word_pos];
			_rand_word_pos--;
			_temp_words.push_back(temp_word);
			m_word_list.erase(m_word_list.begin()+_rand_word_pos);
		}
		m_word_list = _temp_words;
		std::ofstream fout;
		fout.open("new_words.txt");
		if (fout.is_open()) {
			for (int i = 0; i < m_word_list.size(); i++) {
				fout << m_word_list[i] << std::endl;
			}
			fout.close();
		}
		else std::cout << "std::ofstream::fout - ERROR! Failed to open output file new_words.txt!" << std::endl;
	}	
private:
	std::vector<std::string> m_word_list;
};
#endif
