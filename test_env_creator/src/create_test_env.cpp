#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../command/command.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

command cmd;

int main() {
	vector<string> terminal_feedback, error_list;
	cmd.exec("echo \"stuff\"", terminal_feedback, error_list);
	for (int i = 0; i < terminal_feedback.size(); i++) {
		cout << terminal_feedback[i];
	}
	return 0;
}
