//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "tcpserver.h"

const int PORT = 3331;

#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "handler.h"

int main(int argc, const char* argv[])
{
    //Media* list[4];
    Handler h;
    auto group = h.addGroup("group1");
    auto group2 = h.addGroup("group2");
    int* len = new int[5];
    for (int i=0; i<5; i++){
        len[i] = 4*i;
    }
    int* len2 = new int[8];
    for (int i=0; i<8; i++){
        len2[i] = 3+2*i;
    }
    auto test4 = h.addFilm("film.mp4", "path/film.mp4", 456, len, 5);
    auto test5 = h.addVideo("video.mp4", "path/folder/video.mp4", 456);
    group->push_back(test4);
    group2->push_back(test4);
    group->push_back(test5);

    test4->setChapters(len2, 8);

    auto* server =
        new TCPServer( [&](std::string const& request, std::string& response) {
        std::stringstream test;
        std::stringstream test2;
        test<<request;
        std::string temp;
        std::vector<std::string>v;
        while(getline(test,temp,' ')){
            std::cout<<"wow"<<std::endl;
            v.push_back(temp);
        }
            // the request sent by the client to the server
        /*std::cout << "request: " << test.str() << std::endl;
        std::cout << "or: " << v[0]<<std::endl;*/
        if (!v.empty()){
            if(!v[0].compare("print")){
                if(v.size()>1){
                    v.erase(v.begin());// remove "add"
                    for (auto& media : v){
                        h.getMedia(media,test2);
                        //std::cout<<test.str()<<std::endl;
                        response = test2.str();
                    }
                } else {
                    response = "must precise media name";
                }
            } else if(!v[0].compare("printg")){
                if (v.size()>1){
                    v.erase(v.begin());// remove "add"
                    for (auto& group : v){
                        h.printGroup(group);
                    }
                }
            }else if(!v[0].compare("play")){
                if(v.size()>1){
                    h.playMedia(v[1]);// by default only plays the first specified media
                } else {
                    response = "media name must be specified";
                }
            }else {
                response = "RECEIVED: " + request + ", couldn't interprete it";
            }
        } else {
            std::cout<<"je ne comprends rien !"<<std::endl;
        }

            // return false would close the connection with the client
            return true;
        });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
