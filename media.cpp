#include "media.h"

void Media::setName(std::string name){
    name = name;
}


void Media::setPath(std::string path){
    path = path;
}

std::string Media::getName() const {
    return name;
}

std::string Media::getPath() const {
    return path;
}

std::ostream & Media::print( std::ostream &os) const {
    os << name << ' ' << path;
    return os;
}

std::ostream & operator<<( std::ostream &os, const Media &media ){
    return media.print(os);
}

