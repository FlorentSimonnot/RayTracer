#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <memory>

class Object;

class Parser {
public:
	Parser(std::string const& path);
	virtual ~Parser();

	bool parse(std::vector<std::unique_ptr<Object>>& objects);

private:
	std::string m_path;
	std::fstream m_stream;
};