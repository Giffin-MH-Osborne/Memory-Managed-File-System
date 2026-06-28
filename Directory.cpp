#include "Directory.h"

#include <string>
#include <vector>
#include <iostream>

Node* Directory::findChild(const std::string& name) const{
    for(Node* child : children){
        if(child->getName() == name){
            return child;
        }
    }

    return nullptr;
}

void Directory::removeChild(const std::string& name){
    for(auto it = children.begin(); it != children.end(); ++it){
        if((*it)->getName() == name){
            delete *it;
            children.erase(it);
            return;
        }
    }
}

void Directory::listChildren() const {
    for(Node* child : children){
        std::cout << child->getName() << "\n";
    }
}

void Directory::tree(int depth) const {
    for(int i = 0; i < depth; ++i){
        std::cout << "   ";
    }

    std::cout << getName() << "\n";

    for(Node* child : children){
        for(int i = 0; i < depth; ++i){
            std::cout << "   ";
        }

        if(child->getType() == NodeType::Directory){
            static_cast<Directory*>(child) -> tree(depth + 1);
        }
        else{
            std::cout << child -> getName() << "\n";
        }
    }
}


