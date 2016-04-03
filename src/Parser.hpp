#pragma once

#include <fstream>
#include <string>

class Parser {
private:
	std::ifstream m_file;
	bool m_status;
	std::string m_error;

	int readInstruction(std::string const& content, int& pos);

public:
	Parser(std::string const& path);
	virtual ~Parser();

	void parse();
	bool check();
};