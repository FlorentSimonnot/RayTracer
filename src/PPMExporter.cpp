#include "PPMExporter.hpp"
#include <iostream>

PPMExporter::PPMExporter(std::string const& path, int width, int height)
: 	m_stream(path, std::ios::out | std::ios::trunc)
{
	if (m_stream.fail()) {
		std::cerr << "Cannot open file named: " << path << std::endl;
	}
	m_stream << "P3" << std::endl << width << " " << height << "255" << std::endl; 
}

PPMExporter::~PPMExporter() {
	if (m_stream.is_open()) {
		m_stream.close();
	}
}

void PPMExporter::writePixel(Vector const& color) {
	m_stream << color.x() << " " << color.y() << " " << color.z() << "	    ";
}