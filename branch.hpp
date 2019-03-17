#ifndef BRANCH_HPP
#define BRANCH_HPP

#include "dir.hpp"

class branch {
public:
	branch() {}		// ctor
	~branch() {}	// dtor

	void build_branch();
private:
	std::vector<dir> m_dir_list;
};

void branch::build_branch() {
	
}

#endif