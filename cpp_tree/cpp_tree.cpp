#include "pch.h"
#include "dir_obj.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

dir_obj root(NULL, 0);

int main() {
	srand(time(NULL));
	root.dump_dir_contents();
	return 0;
}