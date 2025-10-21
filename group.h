#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <string>
#include <memory>

class Group : public std::list<std::shared_ptr<Media>>
{
private:
    std::string name;
public:
    Group(){}
    Group(std::string name) : name(name) {}
    std::string getName()const{return name;}
    virtual std::ostream& print(std::ostream& os) const {os<<name<<" : ";for (auto& media:*this){os<<*media<<" ";}return os;}
    friend std::ostream& operator<<(std::ostream& os, const Group& group){return group.print(os);}

};

#endif // GROUP_H
