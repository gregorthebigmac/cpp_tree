#ifndef BRANCH_HPP
#define BRANCH_HPP

#include "dir.hpp"

class branch {

public:
	branch() {}		// ctor
	~branch() {}	// dtor

	void build_branch();
	
private:
	std::string m_cwd;
	branch * br_parent;
	std::vector<branch*> br_child;
};

void branch::build_branch() {
	
}

#endif