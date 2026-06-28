#pragma once
#include <string>
#include <vector>
#include "Node.h"

class Directory : public Node {
    std::vector<Node*> children; 

public:
    Directory(const std::string& name, Node* parent)
        :  Node(name, parent) {}

    ~Directory() override {
        for(Node* child : children){
            delete child;
        }
    }

    NodeType getType() const override {return NodeType::Directory;}

    void addChild(Node* child) {
        children.push_back(child);
    }

    const std::vector<Node*>& getChildren() const {
        return children;
    }

    Node* findChild(const std::string& name) const;
    void removeChild(const std::string& name);
    void listChildren() const;
    void tree(int depth = 0) const;
};