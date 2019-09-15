#include "dir_obj.h"
#include "file_obj.h"

// constructor
dir_obj::dir_obj(dir_obj *parent_dir) {
	if (parent_dir != NULL)
		m_parent_dir = parent_dir;
	set_dirname();
	populate_dir();
}
dir_obj::~dir_obj() {} // destructor

// setters
void dir_obj::set_dirname() {
	m_dirname = m_word_list->get_random_word();
}

void dir_obj::populate_dir() {
	srand(time(NULL));
	int number_of_child_objects = (rand() % 15) + 5;
	for (int i = 5; i < number_of_child_objects; i++) {
		bool _bit = rand() % 2;
		if (_bit == 0) {
			file_obj *temp_file = new file_obj(this);
			m_file_ref_list.push_back(temp_file);
			temp_file->set_filename(m_word_list->get_random_word());
		}
		else if (_bit == 1) {
			dir_obj *temp_dir = new dir_obj(this);
			m_dir_ref_list.push_back(temp_dir);
		}
		else std::cout << "dir_obj::populate_dir - ERROR: _bit != 0,1" << std::endl;
	}
}

// private methods
std::string dir_obj::create_filename() {
	if (m_parent_dir != NULL)
		m_word_list = m_parent_dir->get_word_list_ref();
	else m_word_list = new word_list;
}

// debug methods
void dir_obj::dump_dir_contents() {
	std::cout << "Dumping contents of " << m_dirname << ":" << std::endl << std::endl;
	for (int i = 0; i < m_file_ref_list.size(); i++) {
		std::string _filename = m_file_ref_list[i]->get_filename();
		std::cout << _filename << std::endl;
	}
}
