#include "PlayList.h"
#include <vector>
#include <iostream>
/*
incomplete functions:
    constructors
    displayPlayList()
*/
    PlayList::PlayList() : LinkedSet(), tail_ptr_(getPointerToLastNode()) {}

    PlayList::PlayList(const Song &a_song) : LinkedSet(), tail_ptr_(getPointerToLastNode()) {
	    PlayList::add(a_song);
    }

    PlayList::PlayList(const PlayList &a_play_list) : LinkedSet(a_play_list), tail_ptr_(getPointerToLastNode()) {}

    PlayList::~PlayList() {
	    unloop();
    }

    bool PlayList::add(const Song& new_song){
        //need to check if song is already in playlist
        Node<Song>* new_node = new Node<Song>(new_song);
        Node<Song>* test_node = new Node<Song>(new_song);
        if(getPointerTo(new_song, test_node)){
            return false;
        }
        
        
        if(tail_ptr_ != nullptr){
        //if tail_ptr_ is not nullPointer
            //get what tailptr points to
            Node<Song>* tail_ptr_next = tail_ptr_->getNext();

            //sets tailptr to point to new_node
            tail_ptr_->setNext(new_node);

            //sets new_node to point to whatever tailptr pointed to
            new_node->setNext(tail_ptr_next);
        } else {
        //if tail_ptr_ is nullptr
            //sets head_ptr_ to point to whatever the new node is
            head_ptr_ = new_node;
            
        }
        //sets the tailptr for next usage of member variable
        tail_ptr_ = new_node;
        item_count_++;
        return true;
        
    }

    bool PlayList::remove(const Song& a_song){
        /*needs to:
            check if an a_song is in the playlist
            decrement item_count_
            remove a node, but before doing so, get that nodes pointer, and attach it to the playlist

            -> = points to
            ()
            a -> b -> c
        
        */

        //this function should set the previous to point to next
        //(a ->) 
        Node<Song>* previous  = nullptr;
        
        
        //(b)
        Node<Song>* current = getPointerTo(a_song, previous);

        if(current == nullptr){
            return false;
        }
        if(current == tail_ptr_){
            tail_ptr_ = previous;
            item_count_--;
            return true;
        }
        if(current == head_ptr_){
            Node<Song>* next = head_ptr_->getNext();
            head_ptr_ = next;
            delete current;
            item_count_--;
            return true;
        }
        //(c)
        Node<Song>* next = current->getNext();


        //setting (from a -> b to a -> c)
        previous->setNext(next);

        delete current;
        item_count_--;
        return true;
    }

    Node<Song>* PlayList::getPointerToLastNode() const {
        Node<Song>* previous_ptr = nullptr;
        for(Node<Song>* currPointer = head_ptr_; currPointer != nullptr; currPointer =  currPointer->getNext()){
            previous_ptr = currPointer;
        }
        return previous_ptr;
    }
        

    void PlayList::loop(){
        if(tail_ptr_){
            tail_ptr_->setNext(head_ptr_);
        }
    }   
        
    void PlayList::unloop(){
        if(tail_ptr_){
            tail_ptr_->setNext(nullptr);
        }
    }

    void PlayList::displayPlayList(){
        std::vector<Song> vPlaylist = toVector();
        for (int i = 0; i < item_count_; i++)
        {
            std::cout << "* Title: " << vPlaylist[i].getTitle() << "* Author: " << vPlaylist[i].getAuthor() << "* Album: " << vPlaylist[i].getAlbum() << " *" << std::endl;
        }
        std::cout << "End of playlist" << std::endl;
        /*

        * Title: song1* Author: author1* Album: album1 *
        * Title: song2* Author: author2* Album: album2 *
        * Title: song3* Author: author3* Album: album3 *
        std::cout should be of this form
        
        */
    }

    
    // post: previous_ptr is null if target is not in PlayList or if target is the

    // first node, otherwise it points to the node preceding target

    // return: either a pointer to the node containing target

    // or the null pointer if the target is not in the PlayList.
    Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
        previous_ptr = nullptr;
        for(Node<Song>* currPointer = head_ptr_; currPointer != nullptr; currPointer =  currPointer->getNext()){
            if(target == currPointer->getItem()){
                //will return the pointer that points to the target song
                return currPointer;
            }
            previous_ptr = currPointer;
        }
        return nullptr;
    }
