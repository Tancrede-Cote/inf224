#ifndef HANDLER_H
#define HANDLER_H

#include <map>
#include <memory>
#include <string>

#include "group.h"
#include "film.h"
#include "photo.h"

class Handler {
private:
    std::map<std::string,std::shared_ptr<Media>> medias{};
    std::map<std::string,std::shared_ptr<Group>> groups{};
public:
    std::shared_ptr<Photo> addPhoto(std::string name, std::string path, float x, float y){auto temp = std::make_shared<Photo>(name, path, x, y);if(!medias.count(name)){medias.emplace(name,temp);}else{std::cout<<"element "<<name<<" already exists"<<std::endl;}return temp;}
    std::shared_ptr<Video> addVideo(std::string name, std::string path, int len){auto temp = std::make_shared<Video>(name, path, len);if(!medias.count(name)){medias.emplace(name,temp);}else{std::cout<<"element "<<name<<" already exists"<<std::endl;}return temp;}
    std::shared_ptr<Film> addFilm(std::string name, std::string path, int len, int* _chapters, int n){auto temp = std::make_shared<Film>(name, path, len, _chapters, n);if(!medias.count(name)){medias.emplace(name,temp);}else{std::cout<<"element "<<name<<" already exists"<<std::endl;}return temp;}
    std::shared_ptr<Group> addGroup(std::string name){auto temp = std::make_shared<Group>(name);if(!medias.count(name)){groups.emplace(name,temp);}else{std::cout<<"group "<<name<<" already exists"<<std::endl;}return temp;}
    std::shared_ptr<Media> findMedia(std::string name){try {return medias.at(name);}catch(const std::out_of_range& ex){std::cout<<"couldn't find specified element"<<std::endl;}}
    void printMedia(std::string name){try {std::cout<<*medias.at(name)<<std::endl;}catch(const std::out_of_range& ex){std::cout<<"couldn't find specified element"<<std::endl;}}
    std::ostream& getMedia(std::string name, std::ostream& os){try {return medias.at(name)->print(os);}catch(const std::out_of_range& ex){throw std::runtime_error("couldn't find specified element");}}
    void printGroup(std::string name){try {std::cout<<*groups.at(name)<<std::endl;}catch(const std::out_of_range& ex){std::cout<<"couldn't find specified group"<<std::endl;}}
    std::ostream& getGroup(std::string name, std::ostream& os){try {return groups.at(name)->print(os);}catch(const std::out_of_range& ex){throw std::runtime_error("couldn't find specified group");}}
    void playMedia(std::string name){try {medias.at(name)->play();}catch(const std::out_of_range& ex){throw std::runtime_error("couldn't play specified media");}}
};

#endif // HANDLER_H
