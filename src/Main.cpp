//
// Created by Narex on 05/05/2016.
//
#include "Parser.hpp"
#include "Scene.hpp"
#include "RayTracer.hpp"
#include "Gui.hpp"
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <ShapeGenerator.hpp>

void usage() {
	std::cout << "Format : synthese_image -n [level to load] -i [input file] -o [output file]" << std::endl;
}
// lray -n 1 -i <mon_fichier.format> -o image.ppm
// lray -n 2 -ps 16 -i <mon_fichier.format> -o image.ppm
// lray -n 3 -i <mon_fichier.format>

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
				if (s != aaParamArg.size() || aaParam < 1 || aaParam > 16) {
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

//	struct timeval tbegin, tend;
//	gettimeofday(&tbegin, NULL);

	int level = 0;
	int aaParam = 0;
	std::string input, output;

	if (!getOptions(argc, argv, level, input, output, aaParam)) {
		return 0;
	}
	srand(time(NULL));

//	Parser parser(input);
//	std::vector<std::unique_ptr<Object>> objects;
//	parser.parse(objects);

	std::vector<std::unique_ptr<Object>> objects;
	ShapeGenerator shapeGenerator(100);
	shapeGenerator.generate(objects);

//	std::unique_ptr<Object> object;
//	objects.emplace_back(std::move(object));


	Scene scene(objects);
	if (aaParam == 0) {
		aaParam = 1;
	}
	RayTracer rayTracer(aaParam);
	int *image;
	Gui gui;
	if (level == 1 || level == 2) {
		PPMExporter ppme(output, WINDOW_WIDTH, WINDOW_HEIGHT);

		image = rayTracer.draw(scene, ppme);
		gui.render(image);
		delete image;
	}
	if (level > 2) {
		image = rayTracer.draw(scene);
		gui.render(image);
		delete image;
	}
	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) {
			quit = true;
		}
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.scancode) { //voir https://wiki.libsdl.org/SDL_Keycode
				case SDL_SCANCODE_E:
					scene.moveCamera(Camera::Direction::forward);
					image = rayTracer.draw(scene);
					gui.render(image);
					delete image;
					break;
				case SDL_SCANCODE_D:
					scene.moveCamera(Camera::Direction::backward);
					image = rayTracer.draw(scene);
					gui.render(image);
					delete image;
					break;
				case SDL_SCANCODE_S:
					scene.moveCamera(Camera::Direction::left);
					image = rayTracer.draw(scene);
					gui.render(image);
					delete image;
					break;
				case SDL_SCANCODE_F:
					scene.moveCamera(Camera::Direction::right);
					image = rayTracer.draw(scene);
					gui.render(image);
					delete image;
					break;
				case SDL_SCANCODE_Q:
					scene.moveCamera(Camera::Direction::up);
					image = rayTracer.draw(scene);
					gui.render(image);
					delete image;
					break;
				case SDL_SCANCODE_A:
					scene.moveCamera(Camera::Direction::down);
					image = rayTracer.draw(scene);
					gui.render(image);
					delete image;
					break;
				default:
					break;
			}
		}
	}

//	gettimeofday(&tend, NULL);
//	double texec = ((double) (1000 * (tend.tv_sec - tbegin.tv_sec) + ((tend.tv_usec - tbegin.tv_usec) / 1000))) / 1000.;
//	std::cout << "Execution time : " << texec << std::endl;

	return 0;
}