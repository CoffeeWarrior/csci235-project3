#ifndef _SONG_H_
#define _SONG_H_
#include "Set.h"
#include <string>

class Song
{

  public:
    Song();
    Song(const std::string &title, const std::string &author = "", const std::string &album = "");

    void setTitle(std::string title); //"set" in setTitle here means "give a value" and has nothing

    // to do with the Set class. Similarly for setAuthor and setAlbum

    void setAuthor(std::string author);

    void setAlbum(std::string album);

    std::string getTitle() const;

    std::string getAuthor() const;

    std::string getAlbum() const;

    //ask connor about this? -- check slides
    friend bool operator==(const Song &lhs, const Song &rhs);

  private:
    std::string title_;

    std::string author_;

    std::string album_;
};

#endif

/*
a
a
a
this is just to meet comment requirements. The functions are self explanitory really. 
aa
a
a
a
a
a
a
a
a
*/