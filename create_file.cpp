#include "yaml-cpp/yaml.h"
#include "create_file.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "type.h"

using namespace ROSCH;

Parser::Parser(){}

Parser::~Parser(){}

/* for Measurer */
void Parser::create_yaml_file(std::string name,
        int index,
        int core,
        std::vector<std::string> pub_topic,
        std::vector<std::string> sub_topic){
#if 0
  YAML::Emitter out;
  out << YAML::BeginSeq;
  out << YAML::BeginMap;
  out << YAML::Key << "name";
  out << YAML::Value << name;
  out << YAML::Key << "nodeindex";
  out << YAML::Value << index;
  out << YAML::Key << "core";
  out << YAML::Value << core;

  out << YAML::Key << "sub_topic";
  if(sub_topic.size() == 0){
      out << YAML::Value << "null";
  }else{
      out << YAML::Value << YAML::BeginSeq;
      for(int i(0); i < (int)sub_topic.size(); i++){
          out << sub_topic.at(i);
      }
      out << YAML::EndSeq;
  }

  out << YAML::Key << "pub_topic";
  if(pub_topic.size() == 0){
      out << YAML::Value << "null";
  }else{
      out << YAML::Value << YAML::BeginSeq;
      for(int i(0); i < (int)pub_topic.size(); i++){
          out << pub_topic.at(i);
      }
      out << YAML::EndSeq;
  }

  out << YAML::EndMap;
  out << YAML::EndSeq;

  std::ofstream outputfile("./measure_rosch.yaml");
  outputfile << out.c_str();
  outputfile.close();
#endif
}

/* for Scheduler*/
void Parser::create_yaml_file(std::string name,
        int core,
        std::vector<std::string> pub_topic,
        std::vector<std::string> sub_topic){
#if 0
  YAML::Emitter out;
  out << YAML::BeginSeq;
  out << YAML::BeginMap;
  out << YAML::Key << "name";
  out << YAML::Value << name;

  out << YAML::Key << "sub_topic";
  if(sub_topic.size() == 0){
      out << YAML::Value << "null";
  }else{
      out << YAML::Value << YAML::BeginSeq;
      for(int i(0); i < (int)sub_topic.size(); i++){
          out << sub_topic.at(i);
      }
      out << YAML::EndSeq;
  }

  out << YAML::Key << "pub_topic";
  if(pub_topic.size() == 0){
      out << YAML::Value << "null";
  }else{
      out << YAML::Value << YAML::BeginSeq;
      for(int i(0); i < (int)pub_topic.size(); i++){
          out << pub_topic.at(i);
      }
      out << YAML::EndSeq;
  }

  out << YAML::Key << "shed_info";
  out << YAML::BeginMap;
  out << YAML::Key << "core" << YAML::Value << core;
  out << YAML::Key << "priority" << YAML::Value << 25;
  out << YAML::Key << "runtime" << YAML::Value << 10;
  out << YAML::EndMap;
  out << YAML::EndMap;
  out << YAML::EndSeq;

  std::ofstream outputfile("./scheduler_rosch.yaml");
  outputfile << out.c_str();
  outputfile.close();
#endif
}

/* for Tracer */
void Parser::create_yaml_file(std::string name,int core){
#if 0
  YAML::Emitter out;

  out << YAML::BeginSeq;
  out << YAML::BeginMap;
  out << YAML::Key << "name";
  out << YAML::Value << name;
  out << YAML::Key << "core";
  out << YAML::Value << core;
  out << YAML::EndMap;
  out << YAML::EndSeq;

  std::ofstream outputfile("./tracer_rosch.yaml");
  outputfile << out.c_str();
  outputfile.close();
#endif
}

std::vector<node_info_t> Parser::get_node_list(){
    std::vector<node_info_t> node_info;

    return node_info;
}

void Parser::create_file(){
  std::string name = "/talker";
  std::vector<std::string> pub_topic;
  std::vector<std::string> sub_topic;
  int core = 1;
  int index = 21;
  pub_topic.push_back("/chatter");
  pub_topic.push_back("/chatter2");

  create_yaml_file(name,index,core,pub_topic,sub_topic);
  create_yaml_file(name,core,pub_topic,sub_topic);
  create_yaml_file(name,core);
}
