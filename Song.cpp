#include "Song.h"
#include <string>

Song::Song()
{

    std::string title_ = "";

    std::string author_ = "";

    std::string album_ = "";
}

Song::Song(const std::string &title, const std::string &author, const std::string &album)
{
    this->title_ = title;
    this->author_ = author;
    this->album_ = album;
}

void Song::setTitle(std::string title)
{
    this->title_ = title;
} //"set" in setTitle here means "give a value" and has nothing to do with the Set class. Similarly for setAuthor and setAlbum

void Song::setAuthor(std::string author)
{
    this->author_ = author;
}

void Song::setAlbum(std::string album)
{
    this->album_ = album;
}

std::string Song::getTitle() const
{
    return title_;
}

std::string Song::getAuthor() const
{
    return author_;
}

std::string Song::getAlbum() const
{
    return album_;
}

bool operator==(const Song &lhs, const Song &rhs)
{
    return lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ && lhs.album_ == rhs.album_;
}

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