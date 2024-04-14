#include <iostream>
#include <vector>

class Tree{
    public:
        Tree(std::string node_type, std::string value){
           this->node_type = node_type;
           this->value =value;
        }
        std::string node_type;
        std::string value;
        std::vector<Tree *> block;
        std::vector<Tree *> child;
};

