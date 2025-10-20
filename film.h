#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <iostream>

class Film : public Video
{
public:
    Film(){}
    ~Film(){delete[] chapters;}
    Film(std::string name, std::string path, int len, int* _chapters, int n)
        : Video(name, path, len), n(n)
    {
        chapters = new int[n];
        for(int i=0; i<n; i++){
            chapters[i] = _chapters[i];
        }
    }
    virtual std::ostream& print(std::ostream& os) const override {Video::print(os) << " " << n << " chapters : ";for (int i=0; i<n; i++){os<<chapters[i]<<" ";} return os;}
    void setChapters(int* _chapters, int _n){delete chapters; chapters = new int[_n]; for (int i=0; i<_n;i++){chapters[i] = _chapters[i];}n = _n;}
    int getChaptersCount()const{return n;}
    int* getChapters()const{int* res = new int[n];for(int i=0;i<n;i++){res[i]=chapters[i];}return res;}
    friend std::ostream& operator<<(std::ostream& os, const Film& film){return film.print(os);}
protected:
    int* chapters{};
    int n{};
};


#endif // FILM_H
