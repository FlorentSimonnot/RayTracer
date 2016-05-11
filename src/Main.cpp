//
// Created by Narex on 05/05/2016.
//

#include <iostream>
#include "Parser.hpp"
#include "Scene.hpp"
#include "RayTracer.hpp"

void usage() {
    std::cout << "Format : synthese_image -n [level to load] -i [input file] -o [output file]" << std::endl;
}


int main(int argc, char *argv[]) {
	std::string exec = argv[0];
	std::string dir = exec.substr(0, exec.find_last_of('/') + 1);
	Parser parser(dir + "data/test_parser.scn");

	std::vector<std::unique_ptr<Object>> objects;
	parser.parse(objects);

	Scene scene(objects);

	RayTracer rayTracer(40, Point(-5, 0, 0), Vector(1, 0.5, 0));

	rayTracer.draw(scene);

//    if (argc != 7) {
//        usage();
//        return 0;
//    }
//    std::string optionN(argv[1]);
//
//    if (optionN.compare("-n") != 0) {
//        usage();
//        return 0;
//    }
//    std::string valueOfLevel(argv[2]);
//    int value = std::stoi(valueOfLevel);
//
//
//    std::string optionI(argv[3]);
//    if (optionI.compare("-i") != 0) {
//        usage();
//        return 0;
//    }
//    std::string inputFile(argv[4]);
//
//    std::string optionO(argv[5]);
//    if (optionI.compare("-o") != 0) {
//        usage();
//        return 0;
//    }
//
//    std::string outputFile(argv[6]);
//
//    // TODO add parametre
//    switch (value) {
//        case 1:
//            RayTracer::level_1();
//            break;
//        case 2:
//            RayTracer::level_2();
//            break;
//        case 3:
//            RayTracer::level_3();
//            break;
//        case 4:
//            RayTracer::level_4();
//            break;
//    }
//
//
//    Parser parser("./listObjet");

//    parser.parse();


    return 0;
}