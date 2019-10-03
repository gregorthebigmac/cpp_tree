#include "dir_obj.h"
#include "../../command/command.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

command cmd;

int main() {
	srand(time(NULL));
	unsigned int rand_seed = rand();
	dir_obj root(NULL, 0, rand_seed);
	root.dump_dir_contents();
	return 0;
}
