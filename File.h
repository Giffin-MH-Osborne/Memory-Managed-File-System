#pragma once
#include <string>
#include <vector>
#include "Node.h"

class File : public Node {
    std::string content;

public:
    File(const std::string& name, Node* parent) : Node(name, parent) {}

    NodeType getType() const override {return NodeType::File;}

    void write(const std::string& data) {content = data;}
    const std::string& read() const {return content;}
};