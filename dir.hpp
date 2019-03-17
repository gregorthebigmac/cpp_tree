#ifndef DIR_HPP
#define DIR_HPP

#include "command/command.hpp"
#include <string>

class dir {

public:
    dir();  // ctor
    ~dir() {} // dtor

    std::string get_cwd() { return m_cwd;}
    std::string get_parent_dir() { return m_parent_dir; }
    std::vector<std::string>get_dirs();
    std::vector<std::string>get_files();

    int get_branch_level() { return m_branch_level;}
    int get_node_num() { return m_node_level; }
    void classify_objects_in_dir(std::string working_dir);

private:
    void fix_dirs(std::vector<std::string> _dir_list);
    void fix_files(std::vector<std::string> _file_list);
    
    command _cmd;
    int m_branch_level;
    int m_node_level;
    std::string m_cwd;
    std::vector<std::string>m_dirs;
    std::vector<std::string>m_files;
    std::string m_parent_dir;
    bool has_children_dirs;
};

///////////////////////////////////////////////////////////////////////////////////////////////

dir::dir() {
    has_children_dirs = false;
    std::vector<std::string>terminal_feedback;
    std::vector<std::string>error_list;
    _cmd.exec("pwd", terminal_feedback, error_list);
    for (int i = 0; i < terminal_feedback.size(); i++) {
        std::string temp = terminal_feedback[i];
        if (temp[0] == '/')
            m_cwd = temp;
    }
    if (m_cwd.size() < 1)
        std::cout << "I don't think we got a good read on current working dir." << std::endl;
}

void dir::classify_objects_in_dir(std::string working_dir) {
    std::vector<std::string> terminal_feedback;
    std::vector<std::string> error_list;

    std::vector<std::string> _dir_list;
    std::vector<std::string> _file_list;
    std::string list_dir = "ls -la " + m_cwd;
    _cmd.exec(list_dir.c_str(), terminal_feedback, error_list);
    for (int i = 0; i < terminal_feedback.size(); i++) {
        std::string temp = terminal_feedback[i];
        if (temp[0] == 'd')
            _dir_list.push_back(temp);
        else if (temp[0] == '-')
            _file_list.push_back(temp);
        else {
            std::cout << "I don't know what this is!" << std::endl;
            std::cout << temp << std::endl;
        }
    }
    if (m_dirs.size() > 0)
        fix_dirs(_dir_list);
    else
        has_children_dirs = true;
    if (m_files.size() > 0)
        fix_files(_file_list);
}

void dir::fix_dirs(std::vector<std::string> _dir_list) {
    for (int i = 0; i < _dir_list.size(); i++) {
        std::string cur_dir = _dir_list[i];
        std::size_t end_pos = cur_dir.size() - 1;
        cur_dir.erase(end_pos, 1);
        std::size_t found = cur_dir.find_last_of(" ");
        if (found != std::string::npos) {
            std::size_t begin_pos = found + 1;
            std::string pruned_dir = cur_dir.substr(begin_pos, end_pos);
            std::cout << "Found a potential dir: " << std::endl << "[" << pruned_dir << "]" << std::endl;
            if (pruned_dir == ".") {
                std::cout << "ignoring [.]" << std::endl;
                continue;
            }
            if (pruned_dir == "..") {
                std::cout << "ignoring [..]" << std::endl;
                continue;
            }
            else
                m_dirs.push_back(pruned_dir);
}   }   }

void dir::fix_files(std::vector<std::string> _file_list) {
    for (int i = 0; i < _file_list.size(); i++) {
        std::string cur_file = _file_list[i];
        std::size_t end_pos = cur_file.size() - 1;
        cur_file.erase(end_pos, 1);
        std::size_t found = cur_file.find_last_of(" ");
        if (found != std::string::npos) {
            std::size_t begin_pos = found + 1;
            std::string pruned_file = cur_file.substr(begin_pos, end_pos);
            std::cout << "Found a potential file: " << std::endl << "[" << pruned_file << "]" << std::endl;
            m_files.push_back(pruned_file);
        }
    }
}

#endif