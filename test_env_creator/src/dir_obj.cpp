#include "dir_obj.h"
#include "file_obj.h"
#include "../../command/command.hpp"

// constructor
dir_obj::dir_obj(dir_obj *parent_dir, int depth, unsigned int rand_seed) {
	m_job_done = false;
	m_rand_seed = rand_seed;
	if (parent_dir != NULL) {
		m_word_list = parent_dir->get_word_list_ref();
		m_path_to_dir = "/" + parent_dir->get_path_to_dir();
		set_dirname();
	}
	else {
		m_word_list = new word_list;
		std::vector<std::string> working_dir, error_list;
		command cmd;
		cmd.exec("pwd", working_dir, error_list);
		m_path_to_dir = working_dir[0] + "/";
		m_dirname = m_word_list->get_random_word();
		m_path_to_dir = m_path_to_dir + m_dirname;
	}
	m_depth = ++depth;
	m_parent_dir = parent_dir;
	populate_dir();
}
dir_obj::~dir_obj() {} // destructor

void dir_obj::populate_dir() {
	srand(m_rand_seed);
	m_rand_seed = rand();
	int number_of_child_dirs = (rand() % 5) + 2;
	srand(m_rand_seed);
	m_rand_seed = rand();
	int number_of_child_files = (rand() % 5) + 2;
	for (int i = 0; i < number_of_child_dirs; i++) {
		if (m_depth < 5) {
			dir_obj *temp_dir = new dir_obj(this, m_depth, m_rand_seed);
			m_dir_ref_list.push_back(temp_dir);
		}
	}
	for (int i = 0; i < number_of_child_files; i++) {
		if (m_depth < 5) {
		file_obj *temp_file = new file_obj(this);
		m_file_ref_list.push_back(temp_file);
		temp_file->set_filename(m_word_list->get_random_word());
		}
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
		std::cout << m_dir_ref_list[i]->get_dirname() << std::endl;
	}
	for (int i = 0; i < m_dir_ref_list.size(); i++) {
		m_dir_ref_list[i]->dump_dir_contents();
	}
}
