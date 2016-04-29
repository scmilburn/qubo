#include "movement_core.h"

int main(int argc, char **argv) {
	ros::init(argc, argv, "movement_node");
	
	std::unique_ptr<QuboNode> node;

    if(strcmp(argv[1], "tortuga") == 0) {
        node.reset(new moveNode(argc, argv, 10));
    }else{
        ROS_ERROR("the passed in arguments to thruster node (%s) doesn't match anything that makes sense..\n", argv[1]);
        exit(1);
    }

    while (ros::ok()){
        node->update();
        node->publish();

    }

}
