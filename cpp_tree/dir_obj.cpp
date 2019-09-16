#include "pch.h"
#include "dir_obj.h"
#include "file_obj.h"

// constructor
dir_obj::dir_obj(dir_obj *parent_dir, int depth) {
	if (parent_dir != NULL) {
		m_word_list = parent_dir->get_word_list_ref();
		set_dirname();
	}
	else {
		m_word_list = new word_list;
		m_dirname = "ROOT";
	}
	m_depth = ++depth;
	m_parent_dir = parent_dir;
	populate_dir();
}
dir_obj::~dir_obj() {} // destructor

void dir_obj::populate_dir() {
	srand(time(NULL));
	int number_of_child_objects = (rand() % 15) + 5;
	for (int i = 0; i < number_of_child_objects; i++) {
		bool _bit = rand() % 2;
		if (_bit == 0) {
			file_obj *temp_file = new file_obj(this);
			m_file_ref_list.push_back(temp_file);
			temp_file->set_filename(m_word_list->get_random_word());
		}
		else if (_bit == 1) {
			if (m_depth < 10) {
				dir_obj *temp_dir = new dir_obj(this, m_depth);
				m_dir_ref_list.push_back(temp_dir);
			}
			//else std::cout << "Reached level 10. Not creating a new dir." << std::endl;
		}
		else std::cout << "dir_obj::populate_dir - ERROR: _bit != 0,1" << std::endl;
	}
}

// private methods


// debug methods
void dir_obj::dump_dir_contents() {
	std::cout << "Dumping contents of directory:" << std::endl;
	std::cout << "Directory name = " << m_dirname << std::endl;
	if (m_parent_dir == NULL)
		std::cout << "Is Root Directory! Has no parent!" << std::endl;
	else std::cout << "Parent Directory = " << m_parent_dir->get_dirname() << std::endl;
	std::cout << "Files Contained:" << std::endl;
	for (int i = 0; i < m_file_ref_list.size(); i++) {
		std::cout << "File " << i << ": " << m_file_ref_list[i]->get_filename() << std::endl;
	}
	std::cout << "Child Directories:" << std::endl;
	for (int i = 0; i < m_dir_ref_list.size(); i++) {
		m_dir_ref_list[i]->dump_dir_contents();
	}
}
