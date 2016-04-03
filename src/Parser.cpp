#include "Parser.hpp"
#include <sstream>
#include <iostream>

typedef enum {
	INST_TRIANGLE, INST_SPHERE, INST_RECTANGLE, INST_CYLINDER, INST_CAMERA
} Instruction;

static void skipBlanks(std::string const& content, int& pos);
static bool isBlank(char c);
static bool readFloat(std::string const& content, int& pos, float& result);
static bool readInteger(std::string const& content, int& pos, int& result);

Parser::Parser(std::string const& path)
:	m_file(path.c_str()), m_status(true), m_error()
{
	if (m_file.fail()) {
		m_status = false;
		m_error = "File cannot be open.";
	}
}

Parser::~Parser() {
	if(m_file.is_open()){
		m_file.close();
	}
}

void Parser::parse() {
	std::stringstream stream;
	stream << m_file.rdbuf();
	std::string content = stream.str();
	int pos = 0;

	while (pos < content.length()) {
		int inst = readInstruction(content, pos);
		if (inst < 0) {
			return;
		}



	}

	// Tant que c'est pas la fin du fichier

		// Lire une instruction (séquence de charactères en minuscule)

		// Lire les caractères qui servent à rien.

		// Lire les paramètres de l'instruction (etc.)

		// Lire les caractères qui servent à rien.

}

bool Parser::check() {
	if (m_status) {
		return true;
	}

	std::cerr << "Error while parsing: " << m_error << std::endl;
	return m_status;
}

int Parser::readInstruction(std::string const& content, int& pos) {
	std::string inst;
	int begin = pos;
	
	skipBlanks(content, pos);
	while (pos < content.length() && content[pos] >= 'a' && content[pos] <= 'z'){	
		++ pos;
	}

	inst = content.substr(begin, pos - begin);

	if (inst == "triangle") {
		return INST_TRIANGLE;
	} else if (inst == "sphere"){
		return INST_SPHERE;
	} else if (inst == "rectangle"){
		return INST_RECTANGLE;
	} else if (inst == "cylinder"){
		return INST_CYLINDER;
	} else if (inst == "camera"){
		return INST_CAMERA;
	} else {
		m_status = false;
		m_error = "Unknown instruction '" + inst + "'.";
		return -1;
	}
}



void skipBlanks(std::string const& content, int& pos) {
	while (pos < content.length() && isBlank(content[pos])) {
		++ pos;
	}
}

bool isBlank(char c) {
	return c == ' ' || c =='\n' || c =='\r' || c == '\t';
}

bool readFloat(std::string const& content, int& pos, float& result) {
	skipBlanks(content, pos);
	size_t end;
	result = std::stof(content.substr(pos), &end);
	pos += end;
	return end != 0;
}

bool readInteger(std::string const& content, int& pos, int& result) {
	skipBlanks(content, pos);
	size_t end;
	result = std::stoi(content.substr(pos), &end);
	pos += end;
	return end != 0;
}