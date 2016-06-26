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
#include <ShapeGenerator.hpp>

void usage() {
    std::cout <<
    "\nFormat : ./bin/synthese_image -n [level to load] -i [input file] -o [output file] -r [number of elements]\n"
    << "The input file contains the scene that you want to load\n"
    << "The output file is the name of the file for ppme format export\n"
    << "The number of elements is the number of elements you want to randomly generate\n"
    << "If the -r option is active , the input file wont be red\n"
    << "If the level number is > 2, the output file wont be created\n"
    << "The level 1 & 2 require an output file\n"
    << "h -> show this usage"
    << std::endl;
}
// lray -n 1 -i <mon_fichier.format> -o image.ppm
// lray -n 2 -ps 16 -i <mon_fichier.format> -o image.ppm
// lray -n 3 -i <mon_fichier.format>

static bool getOptions(int argc, char** argv, int& level, std::string& input, std::string& output, int& aaParam,
                       bool& isRandomGenerated, int& numberGenerated) {
    char opt;
    std::string levelArg, aaParamArg, numberGeneratedArg;

    bool fail = false;
    size_t s;
    level = 0;
    aaParam = 0;

    while ((opt = getopt(argc, argv, "n:s:i:o:r:h")) != -1) {
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
            case 'r' :
                numberGeneratedArg = optarg;
                numberGenerated = std::stoi(numberGeneratedArg, &s);
                if (s != numberGeneratedArg.size()) {
                    std::cerr << "ERROR : no value for \"-r\" option" << std::endl;
                    fail = true;
                }
                isRandomGenerated = true;
                break;
            case 'h' :
                usage();
                break;
            default:
                fail = true;
                break;
        }
    }

    if (fail
        || level == 0
        || (input.empty() && isRandomGenerated == false)
        || (output.empty() && level < 3)
        || (aaParam == 0 && level == 2)
            ) {
        usage();
        return false;
    }

    return true;
}


int main(int argc, char* argv[]) {

//	struct timeval tbegin, tend;
//	gettimeofday(&tbegin, NULL);

    int level = 0;
    int aaParam = 0;
    std::string input, output;
    bool isRandomGenerated = false;
    int numberGenerated = 100;

    if (!getOptions(argc, argv, level, input, output, aaParam, isRandomGenerated, numberGenerated)) {
        return 0;
    }
    srand(time(NULL));


    std::vector<std::unique_ptr<Object>> objects;
    if (isRandomGenerated) {
        ShapeGenerator shapeGenerator(numberGenerated);
        shapeGenerator.generate(objects);
    }
    else {
        Parser parser(input);
        parser.parse(objects);

        // Extraction liste materiaux
        std::vector<Materiaux*> m_materiaux;
        for (auto& o: objects) {
            if (Materiaux* m = dynamic_cast<Materiaux*>(o.get())) {
                m_materiaux.emplace_back(m);
            }
        }

//        for (Materiaux* m:m_materiaux) {
//            std::cout << "\nmat = " << m->getName() << std::endl;
//        }

        bool testMat = true;
        for (auto& o: objects) {
            if (Shape* s = dynamic_cast<Shape*>(o.get())) {
                for (Materiaux* m:m_materiaux) {
                    if (s->getMaterial().getName() == m->getName()) {
                        s->setMaterial(*m);
                        testMat = false;
                        break;
                    }
                }
                if (testMat) {
                    std::cout << "Material " << s->getMaterial().getName() <<
                    " doesn't exist , setting default material" << std::endl;
                    s->setMaterial(Materiaux());
                }
            }
            testMat = true;
        }
    }

    ////////////////////////////////////////////



    ////////////////////////////////////////////
    Scene scene(objects);
    if (aaParam == 0) {
        aaParam = 1;
    }
    RayTracer rayTracer(aaParam);
    int* image;
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
    while (!quit) {
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
                case SDL_SCANCODE_W:
                    scene.rotateCamera(Camera::Direction::left);
                    image = rayTracer.draw(scene);
                    gui.render(image);
                    delete image;
                    break;
                case SDL_SCANCODE_R:
                    scene.rotateCamera(Camera::Direction::right);
                    image = rayTracer.draw(scene);
                    gui.render(image);
                    delete image;
                    break;
                case SDL_SCANCODE_T:
                    scene.rotateCamera(Camera::Direction::up);
                    image = rayTracer.draw(scene);
                    gui.render(image);
                    delete image;
                    break;
                case SDL_SCANCODE_G:
                    scene.rotateCamera(Camera::Direction::down);
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