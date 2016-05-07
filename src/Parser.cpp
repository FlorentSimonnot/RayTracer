#include "Parser.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Cylinder.hpp"
#include <iostream>
#include <sstream>

static bool parseType(std::string const& content, size_t& pos, std::string& type);
static bool parseScalar(std::string const& content, size_t& pos, float& scalar);

static bool parseVector(std::string const& content, size_t& pos, Vector& vector);
static bool parsePoint(std::string const& content, size_t& pos, Point& point);
static bool parseEnd(std::string const& content, size_t& pos);
static void consumeBlank(std::string const& content, size_t& pos);

static bool parseInstruction(std::string const& content, size_t& pos, std::unique_ptr<Object>& object);

static bool parseWord(std::string const& content, size_t& pos, std::string& word);
static bool isCharacter(char c);
static bool isBlank(char c);

static bool parseSphere(std::string const& content, size_t& pos, std::unique_ptr<Object>& object);
static bool parseTriangle(std::string const& content, size_t& pos, std::unique_ptr<Object>& object);
static bool parseRectangle(std::string const& content, size_t& pos, std::unique_ptr<Object>& object);
static bool parseCylinder(std::string const& content, size_t& pos, std::unique_ptr<Object>& object);

Parser::Parser(std::string const& path)
:	m_path(path), m_stream(path)
{
}

Parser::~Parser() {
	if (m_stream.is_open()) {
		m_stream.close();
	}
}

bool Parser::parse(std::vector<std::unique_ptr<Object>>& objects) {
	if (m_stream.fail()) {
		std::cerr << "Cannot open file " << m_path << "." << std::endl;
		return false;
	}

	std::stringstream ss;
	ss << m_stream.rdbuf();
	std::string content = ss.str();
	size_t pos = 0;

	while (!parseEnd(content, pos)) {
		if (pos >= content.length()) {
			std::cerr << "Unexpected end of string." << std::endl;
			return false;
		}

		std::unique_ptr<Object> object;
		if (!parseInstruction(content, pos, object)) {
			return false;
		}

		objects.emplace_back(std::move(object));
	}

	return true;
}

bool parseInstruction(std::string const& content, size_t& pos, std::unique_ptr<Object>& object) {
	std::string type;
	if (parseType(content, pos, type)) {
		if (type == "sphere") {
			return parseSphere(content, pos, object);
		} else if (type == "triangle") {
			return parseTriangle(content, pos, object);			
		} else if (type == "rectangle") {
			return parseRectangle(content, pos, object);
		} else if (type == "cylinder") {
			return parseCylinder(content, pos, object);
		}
	}

	return false;
}

bool parseType(std::string const& content, size_t& pos, std::string& type) {
	consumeBlank(content, pos);
	return parseWord(content, pos, type);
}

bool parseScalar(std::string const& content, size_t& pos, float& scalar) {
	consumeBlank(content, pos);
	size_t size;
	scalar = std::stof(content.substr(pos), &size);
	pos += size;
	return size != 0;
}

bool parseVector(std::string const& content, size_t& pos, Vector& vector) {
	float x, y, z;
	consumeBlank(content, pos);
	if (content[pos] == '(') {
		++ pos;
		if (parseScalar(content, pos, x) && parseScalar(content, pos, y) && parseScalar(content, pos, z)) {
			consumeBlank(content, pos);
			if (content[pos] == ')') {
				++ pos;
				vector = Vector(x, y, z);
				return true;
			}
		}
	}

	return false; 
}

bool parsePoint(std::string const& content, size_t& pos, Point& point) {
	return parseVector(content, pos, point);
}

bool parseEnd(std::string const& content, size_t& pos) {
	consumeBlank(content, pos);
	return pos == content.length();
}

void consumeBlank(std::string const& content, size_t& pos) {
	while (pos < content.length() && isBlank(content[pos])) {
		++ pos;
	}
}

bool parseWord(std::string const& content, size_t& pos, std::string& word) {
	size_t start = pos;
	while (pos < content.length()) {
		if (!isCharacter(content[pos])) {
			word = content.substr(start, pos - start);
			return pos != start;
		}

		++ pos;
	}

	return false;
}

bool isCharacter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); 
}

bool isBlank(char c) {
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

bool parseSphere(std::string const& content, size_t& pos, std::unique_ptr<Object>& object) {
	Vector position, rotation, scale;
	if (parseVector(content, pos, position) && parseVector(content, pos, rotation) &&
		parseVector(content, pos, scale)) {
		object.reset(new Sphere(position, rotation, scale));
		return true;
	}

	return false;
}

bool parseTriangle(std::string const& content, size_t& pos, std::unique_ptr<Object>& object) {
	Point p1, p2, p3;
	if (parsePoint(content, pos, p1) && parsePoint(content, pos, p2) && parsePoint(content, pos, p3)) {
		object.reset(new Triangle(p1, p2, p3));
		return true;
	}

	return false;
}

bool parseRectangle(std::string const& content, size_t& pos, std::unique_ptr<Object>& object) {
	Vector position, rotation, scale;
	if (parseVector(content, pos, position) && parseVector(content, pos, rotation) &&
		parseVector(content, pos, scale)) {
		object.reset(new Rectangle(position, rotation, scale));
		return true;
	}

	return false;
}

bool parseCylinder(std::string const& content, size_t& pos, std::unique_ptr<Object>& object) {
	Vector position, rotation, scale;
	if (parseVector(content, pos, position) && parseVector(content, pos, rotation) &&
		parseVector(content, pos, scale)) {
		object.reset(new Cylinder(position, rotation, scale));
		return true;
	}

	return false;
}
