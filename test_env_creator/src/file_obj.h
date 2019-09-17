#ifndef FILE_OBJ_HPP
#define FILE_OBJ_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

class dir_obj;

class file_obj {
public:
	file_obj(dir_obj *parent_dir) {
		m_parent_dir = parent_dir;
	}
	~file_obj() {}

	// getters
	std::string get_filename() { return m_filename; }
	std::string get_path_to_file() { return m_path_to_file; }
	std::string get_file_permissions_as_string() { return m_str_permissions; }
	std::vector<int> get_file_permissions_as_vec_int() { return m_vec_int_permissions; }

	// setters
	void set_filename(std::string filename) { m_filename = filename; }
	void set_path_to_file(std::string path) { m_path_to_file = path; }

private:
	void set_file_attributes();

	std::string m_filename;
	std::string m_path_to_file;
	std::string m_str_permissions;
	std::vector<int> m_vec_int_permissions;
	dir_obj *m_parent_dir;
	int m_file_size;
};

#endif
