#pragma once
#include <string>

enum class NodeType {File, Directory};

class Node {
protected:
    std::string name;
    Node* parent;
public:
    Node(const std::string& name, Node* parent)
        : name(name), parent(parent) {}
    
    virtual ~Node() = default;

    const std::string& getName() const {return name;}
    Node* getParent() const {return parent;}
    virtual NodeType getType() const = 0;
};