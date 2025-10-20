#ifndef PHOTO_H
#define PHOTO_H
#include <iostream>
#include "media.h"

class Photo : public Media
{
private:
    float x{};
    float y{};
public:
    Photo(){}
    Photo(std::string name, std::string path, float x, float y) : Media(name, path), x(x), y(y){}
    ~Photo(){}
    virtual std::ostream& print(std::ostream& os) const override {Media::print(os) << ' ' << x << "x" << y; return os;}
    friend std::ostream& operator<<(std::ostream& os, const Photo& photo) {return photo.print(os);}
    void setX(float x){x=x;}
    void setY(float y){y=y;}
    float getX() const {return x;}
    float getY() const {return y;}
    void play() const override {std::system(("imagej " + path + " &").c_str());}

};

#endif // PHOTO_H
