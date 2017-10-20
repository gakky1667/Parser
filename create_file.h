#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <stdlib.h>
#include "type.h"

namespace ROSCH {
class Parser{
public:
    Parser();
    ~Parser();
    void create_file();
    std::vector<node_info_t> get_node_list();

private:
    /* for Measurer */
    void create_yaml_file(
            std::string name,
            int index,
            int core,
            std::vector<std::string> pub_topic,
            std::vector<std::string> sub_topic
            );

    /* for Scheduler*/
    void create_yaml_file(
            std::string name,
            int core,
            std::vector<std::string> pub_topic,
            std::vector<std::string> sub_topic
            );

    /* for Tracer */
    void create_yaml_file(std::string name,int core);

};
}
#endif // CREATE_FILE_H
