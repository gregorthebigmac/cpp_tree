#ifndef DIR_OBJ_HPP
#define DIR_OBJ_HPP
#include "word_list.h"

class file_obj;

class dir_obj {
public:
	dir_obj(dir_obj *parent_dir);
	~dir_obj();
	
	// getters
	std::string get_dirname() { return m_dirname; }
	std::string get_path_to_dir() { return m_path_to_dir; }
	std::vector<file_obj*> get_file_objs_refs() { return m_file_ref_list; }
	word_list *get_word_list_ref() { return m_word_list; }
	
	// setters
	void set_dirname();
	
	void populate_dir();
	
	// debug methods
	void dump_dir_contents();
	
private:
	std::string create_filename();
	
	std::string m_dirname;
	std::string m_path_to_dir;
	dir_obj *m_parent_dir;
	std::vector<dir_obj*> m_dir_ref_list;
	std::vector<file_obj*> m_file_ref_list;
	word_list *m_word_list;
};

#endif
