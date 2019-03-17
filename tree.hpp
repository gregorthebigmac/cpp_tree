#ifndef TREE_HPP
#define TREE_HPP

#include "branch.hpp"

class tree {
public:
	tree() {}
	~tree() {}

	void build_tree();

private:
	std::vector<branch> m_branch_list;
};

void tree::build_tree() {
	
}

#endif