//
// Created by Narex on 04/05/2016.
//

#ifndef PROJECT_OBJET_HPP
#define PROJECT_OBJET_HPP

class Objet {
private:
    int color_;

public:
    Objet(void);

    Objet(const Objet &c);

    ~Objet();

    void setColor(int color);
    int getColor();

};

#endif //PROJECT_OBJET_HPP
