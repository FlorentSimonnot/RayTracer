# Raytracer 

## You need the SDL2 libraries installed to be able to compil & run the program
   * Here is a link to how to do it on the different platforms https://wiki.libsdl.org/Installation
   * This program should be run on a linux OS, we didn't try on others one, feel free to try and give feedback :)

## How to use it :

* Usage using command line: 
  * Go in the "build" directory
  * run "cmake .."
  * run "make"
  * run the program ( options are written below )

* Program options :
    * You need at least the -n option with another option such as -i for the input file or -r to randomly generate items
    * Format : ./bin/synthese_image -n [level to load] -i [input file] -o [output file] -r [number of elements] -s[value]
    * -n [value] : level to load
    * -i [input file] : The input file contains the scene that you want to load
    * -o [output file]: The output file is the name of the file for ppme format export
    * -r [value]: The number of elements is the number of elements you want to randomly generate
        * If the -r option is active , the input file wont be red     
    * If the level number is superior to 2 , the output file wont be created
    * The levels 1 & 2 require an output file
    * -s [value] : AA(Anti aliasing) value can be 0 (default), 2, 4, 8, 16 no other values
    * -h : show this usage

### How to create a file to try the program
For a material :
  * material name coefRelfection transparence indiceRefraction brillance
    * Example : material wood 100 50 100 0
For the camera :
  * camera depth position orientation
    * Exemple : camera 50 (-5 0 0) (1 0 0)
For any other object :
  * type position rotation scale color angle material
    * Example : sphere (3 -3 3) (0 0 1) (1.0 1.0 1.0) (255 0 0) 0 wood
  

### Commands 
* Program commands once launched (All have been done with a QWERTY keyboard, some controls can feel weird on an AZERTY layout):
  * Camera movement :
    * E : Move FORWARD
    * D : Move BACKWARD
    * S : Move LEFT
    * F : Move RIGHT
    * Q : Move UP
    * A : Move DOWN
  * Camera rotation :
    * W : Rotate LEFT
    * R : Rotate RIGHT
    * T : Rotate UP
    * G : Rotate DOWN
    
Here are some examples :

* ./bin/Synthese_Image -n 3 -r 100 -s 4
  * This will create 100 random items in the scene, with AA set to 4
* ./bin/Synthese_Image -n 2 -i myFile -o anotherFile.ppm
  * This will read the file, generate the objects and export the file to ppm format.
   
