#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

typedef struct SchedInfo{
    int core;
    int priority;
    int run_time;
} SchedInfo;

typedef struct node_info_t{
    std::string name;
    int index;
    int core;
    std::vector<std::string> sub_topic;
    std::vector<std::string> pub_topic;
    int deadline;
    std::vector<SchedInfo> sched_info;
} node_info_t;


#endif // TYPE_H
