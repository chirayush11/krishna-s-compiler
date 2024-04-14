#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "parser.hpp"

extern int yylex();
extern Tree * root;

/*
 * These values are globals defined in the parsing function.
 */
extern std::string* target_program;
extern std::set<std::string> symbols;
int a = 0;
void print_node(std::string variable_name, std::string node_value){
  std::cout<<variable_name<<" "<<"[label=\""<<node_value<<"\"];\n"<<std::endl;

}
void print_connection(std::string child, std::string parent){
  std::cout<<parent<<" -> "<<child<<";\n"<<std::endl;
}
void print_tree(Tree *node,std::string parent){
  std::string current_node;
  if(node == NULL){
    return;
  }
    std::ostringstream stm ;
    stm << a ;
    current_node = node->node_type + stm.str();
    a++;
    if(node->node_type != "STATEMENT"){
      print_node(current_node, node->node_type + (node->value.size() > 0 ? (" " + node->value) : ""));
      print_connection(current_node,parent);
    }
    for (std::vector<Tree *>::iterator it = node->block.begin() ; it != node->block.end(); it++){
      print_tree(*it,parent);
    }
    for (std::vector<Tree *>::iterator it = node->child.begin() ; it != node->child.end(); it++){
      print_tree(*it,current_node);
    }
}

int main() {
  if (!yylex()) {
    std::cout << "digraph G {" << std::endl;
    print_tree(root,"block");
    std::cout << "}" << std::endl;
  }
}
