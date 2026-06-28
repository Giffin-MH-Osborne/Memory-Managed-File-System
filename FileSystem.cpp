#include "FileSystem.h"
#include <iostream>

void FileSystem::mkdir(const std::string& name){
    if(current -> findChild(name)){
        std::cout << "Directory already exists: " << name << "\n";
        return;
    }

    current -> addChild(new Directory(name, current));
}

void FileSystem::touch(const std::string& name){
    if(current -> findChild(name)){
        std::cout << "File already exists: " << name << "\n";
        return;
    }

    current -> addChild(new File(name, current));
}

void FileSystem::ls(){
    current -> listChildren();
}

void FileSystem::cd(const std::string& path){
    if(path == ".."){
        if(current -> getParent()){
            current = static_cast<Directory*>(current->getParent());
        }
        return;
    }
    Node* child = current -> findChild(path);
    if(!child){
        std::cout << "No such directory: " << path << "\n";
        return;
    }

    if(child->getType() != NodeType::Directory){
        std::cout << path << " is not a directory\n";
        return;
    }

    current = static_cast<Directory*>(child);
}

void FileSystem::pwd() const {
    std::vector<std::string> parts;
    const Directory* dir = current;

    while(dir != nullptr){
        parts.push_back(dir->getName());
        dir = static_cast<Directory*>(dir -> getParent());
    }

    for(auto it = parts.rbegin(); it != parts.rend(); ++it){
        std::cout << "/" << *it;
    }
    std::cout << "\n";
}

void FileSystem::rm(const std::string& path){
    Node* child = current -> findChild(path);
    if(!child){
        std::cout << "No such file or directory: " << path << "\n";
        return;
    }
    current -> removeChild(path);
}

void FileSystem::cat(const std::string& path){
    Node* child = current -> findChild(path);
    if(!child){
        std::cout << "No such file: " << path << "\n";
        return;
    }
    
    if(child -> getType() == NodeType::Directory){
        std::cout << path << " is a directory";
        return;
    }

    File* file = static_cast<File*>(child);
    std::cout << file -> read() << "\n";
}

void FileSystem::write(const std::string& path, const std::string& data){
    Node* child = current -> findChild(path);
    
    if(!child){
        std::cout << "No such file: " << path << "\n";
        return;
    }
    
    if(child -> getType() == NodeType::Directory){
        std::cout << path << " is a directory";
        return;
    }

    File* file = static_cast<File*>(child);
    file -> write(data);
}

void FileSystem::tree() const {
    current -> tree(0);
}

std::vector<std::string> FileSystem::tokenize(const std::string& path) const {
    std::vector<std::string> tokens;
    std::string current;

    for(char c : path){
        if(c == '/'){
            if(!current.empty()){
                tokens.push_back(current);
                current.clear();
            }
        }
        else
        {
            current.push_back(c);
        }
    }

    if(!current.empty()){
        tokens.push_back(current);
    }

    return tokens;
}

Node* FileSystem::resolvePath(const std::string& path){
    Directory* start;
    if(!path.empty() && path[0] == '/'){
        start = root;
    } else{
        start = current;
    }

    std::vector<std::string> parts = tokenize(path);
    Node* node = start;

    for(const std::string& part : parts){
        if(part == "."){
            continue;
        }
        
        if(part == ".."){
            if(node -> getParent()){
                node = node -> getParent();
            }
            continue;
        }

        if(node -> getType() != NodeType::Directory){
            return nullptr;
        }

        Directory* dir = static_cast<Directory*>(node);
        Node* child = dir -> findChild(part);

        if(!child){
            return nullptr;
        }

        node = child;
    }

    return node;
}



