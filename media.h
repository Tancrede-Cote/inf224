#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>

class Media
{
public:
    Media(){}
    Media(std::string name, std::string path) : name(name), path(path){}
    virtual ~Media(){}
    void setName(std::string);
    void setPath(std::string);
    std::string getName() const;
    std::string getPath() const;
    virtual void play() const{}
    virtual std::ostream& print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Media& media);
protected:
    std::string name{};
    std::string path{};
};

std::ostream& operator<<(std::ostream& os, const Media& media);

#endif // MEDIA_H
