#ifndef VIDEO_H
#define VIDEO_H

#include "media.h"

class Video : public Media
{
protected:
    int len{};
public:
    Video(){}
    Video(std::string name, std::string path, int len) : Media(name, path), len(len) {}
    ~Video(){}
    virtual std::ostream& print(std::ostream& os) const override {Media::print(os) << " " << len << "s"; return os;}
    friend std::ostream& operator<<(std::ostream& os, const Video& video){return video.print(os);}
    void setLen(int len){len=len;}
    int getLen() const {return len;}
    void play() const override {std::system(("mpv " + path + " &").c_str());}

};

#endif // VIDEO_H
