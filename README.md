# Raytracer 

## You need the SDL2 libraries installed to be able to compil & run the program
   * Here is a link to how to do it on the different platforms https://wiki.libsdl.org/Installation
   * This program should be run on a linux OS, we didn't try on others one, free to you to try and give feedback :)

## How to use it :

* Usage using command line: 
    * Go in the "build" directory
    * run "cmake .."
    * run "make"
    * run the program ( options are written below )

* Program options :
    * You need at least the -n option with another option such as -i for the input file or -r to randomly generate items
    * ./bin/synthese_image -n [level to load] -i [input file] -o [output file] -r [number of elements]
    * -n [value] : level to load
    * -i [input file] : The input file contains the scene that you want to load
    * -o [output file]: The output file is the name of the file for ppme format export
    * -r [value]:  
        * The number of elements is the number of elements you want to randomly generate
        * If the -r option is active , the input file wont be red
          
    * If the level number is 3 or higher, the output file wont be created
    * The levels 1 & 2 require an output file
    * -s [value] : AA(Anti aliasing) value can be 2 to 16 (included), the best would be using only the following values 2, 4, 8, 16, the other ones may produce something odd
    * -h -> show this usage

He is an example :
* ./bin/Synthese_Image -n 3 -r 100 -s 4
* This will create 100 random items in the scene, with AA set to 4
 
* ./bin/Synthese_Image -n 2 -i myFile -o anotherFile.ppm
