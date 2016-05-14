//
// Created by Narex on 05/05/2016.
//
#include "Parser.hpp"
#include "Scene.hpp"
#include "RayTracer.hpp"
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

void usage() {
    std::cout << "Format : synthese_image -n [level to load] -i [input file] -o [output file]" << std::endl;
}
// lray -n 1 -i <mon_fichier.format> -o image.ppm
// lray -n 2 -ps 16 -i <mon_fichier.format> -o image.ppm
// lray -n 3 -i <mon_fichier.format>
// int getOpt(int argc, char *argv[], char *options){

// }

static bool getOptions(int argc, char **argv, int& level, std::string& input, std::string& output, int& aaParam) {
	char opt;
	std::string levelArg, aaParamArg;

	bool fail = false;
	size_t s;
	level = 0;
	aaParam = 0;

	while ((opt = getopt(argc, argv, "n:s:i:o:")) != -1) {
	 	switch (opt) {
	 	case 'n' :
	 		levelArg = optarg;
			level = std::stoi(levelArg, &s);
			if (s != levelArg.size() || level < 1 || level > 3) {
				fail = true;
			}
	 		break;

	 	case 's' :
	 		aaParamArg = optarg;
			aaParam = std::stoi(aaParamArg, &s);
			if (s != levelArg.size() || aaParam < 1 || aaParam > 16) {
				fail = true;
			}
	 		break;

	 	case 'i' :
	 		input = optarg;
	 		break;

	 	case 'o' :
	 		output = optarg;
	 		break;

	 	default:
	 		fail = true;
	 		break;
	 	}
	}

	if (fail
		|| level == 0
		|| input.empty() 
		|| (output.empty() && level < 3) 
		|| (aaParam == 0 && level == 2)
	) {
		usage();
		return false;
	}

	return true;
}



int main(int argc, char *argv[]) {

	int level = 0;
	int aaParam = 0;
	std::string input, output;

	if (!getOptions(argc, argv, level, input, output, aaParam)) {
		return 0;
	}

//	std::string exec = argv[0];
//	std::string dir = exec.substr(0, exec.find_last_of('/') + 1);
//	Parser parser(dir + "data/test_parser.scn");
	Parser parser(input);
	srand(time(NULL));

	std::vector<std::unique_ptr<Object>> objects;
	parser.parse(objects);

	Scene scene(objects);

	scene.test();
	PPMExporter ppme(output, WINDOW_WIDTH, WINDOW_HEIGHT);

	RayTracer rayTracer(1);

	rayTracer.draw(scene, ppme);
	scanf("%*c");


    return 0;
}