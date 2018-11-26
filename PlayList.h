#pragma once
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song>{
    public:
        PlayList();
        PlayList(const Song& a_song);
        PlayList(const PlayList& a_play_list); //copy constructor
         ~PlayList(); // destructor

        bool add(const Song& new_song) override;

        bool remove(const Song& a_song) override;
        Node<Song>* getPointerToLastNode() const;
        
        

        void loop();    
        
        void unloop();

        void displayPlayList();
    private:
        Node<Song>* tail_ptr_; // Pointer to last node
        Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
        Song Search(const Song& a_song);
};