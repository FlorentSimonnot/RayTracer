#pragma once

#include <stdio.h>
#include <fstream>
#include "Vector.hpp"

class PPMExporter {
public:
	PPMExporter(std::string const& path, int width, int height);
	virtual ~PPMExporter();

	void writePixel(Vector const& color);

private:
	std::fstream m_stream;
};