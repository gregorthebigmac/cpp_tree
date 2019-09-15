#include "file_obj.h"
#include "dir_obj.h"

void file_obj::set_file_attributes() {
	srand(time(NULL));
	std::string temp_permissions = "-000000000";
	for (int i = 1; i < 9; i++) {
		bool _bit = rand() % 2;
		if ((i == 1) || (i == 4) || (i == 7)) {
			if (_bit == 0)
				temp_permissions[i] = 'r';
			else temp_permissions[i] = '-';
		}
		else if ((i == 2) || (i == 5) || (i == 8)) {
			if (_bit == 0)
				temp_permissions[i] = 'w';
			else temp_permissions[i] = '-';
		}
		else if ((i == 3) || (i == 6) || (i == 9)) {
			if (_bit == 0)
				temp_permissions[i] = 'x';
			else temp_permissions[i] = '-';
		}
		else std::cout << "file_obj: ERROR: i != 1,2,3,4,5,6,7,8,9" << std::endl;
	}
	std::cout << "Dumping temp_permissions of " << m_filename << ":" << std::endl;
	std::cout << temp_permissions << std::endl;
}
