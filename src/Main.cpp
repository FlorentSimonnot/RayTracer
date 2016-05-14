//
// Created by Narex on 05/05/2016.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Parser.hpp"
#include "Scene.hpp"
#include "RayTracer.hpp"
#include <sys/time.h>
void usage() {
    std::cout << "Format : synthese_image -n [level to load] -i [input file] -o [output file]" << std::endl;
}


int main(int argc, char *argv[]) {
	struct timeval tbegin, tend;
	gettimeofday(&tbegin, NULL);

	std::string exec = argv[0];
	std::string dir = exec.substr(0, exec.find_last_of('/') + 1);
	Parser parser(dir + "data/test_parser.scn");
	srand(time(NULL));

	std::vector<std::unique_ptr<Object>> objects;
	parser.parse(objects);


	Scene scene(objects);

	// Profondeur de vue , Position de la camera , orientation de la camera , anti aliasing
	// Temps d'execution de l'AA:
	//  x1 = 3.1s
	//  x2 =
	//  x4 =
	//  x8 = 20.8s
	//  x16 = 40.5s
	// Les valeurs sont des arrondies , elle ne sont la que pour donner un ordre d'idée
	// Et ne pas s'inquieter en cas de test
	RayTracer rayTracer(50, Point(-5, 0, 0), Vector(1, 0, 0), 1);

	// Toujours faire updateCamera avant de draw si jamais on bouge la camera
//	rayTracer.updateCamera(50, Point(-5, 0, 0), Vector(1, 0, 0));
	rayTracer.draw(scene);

	gettimeofday(&tend, NULL);
	double texec = ((double) (1000 * (tend.tv_sec - tbegin.tv_sec) + ((tend.tv_usec - tbegin.tv_usec) / 1000))) / 1000.;
	std::cout << "Execution time : " << texec << std::endl;
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