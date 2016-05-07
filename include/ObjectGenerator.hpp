//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
#define SYNTHESE_IMAGE_OBJECTGENERATOR_HPP


class ObjectGenerator {
private:
    float m_numberObjects;

public:
    ObjectGenerator();
    ObjectGenerator(float numberObjects);
    virtual ~ObjectGenerator();

    //TODO A changer en tableau d'objet pour le retour
    void generate();
};


#endif //SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
