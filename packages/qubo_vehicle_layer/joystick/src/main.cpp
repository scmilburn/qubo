#include "JoyReader.h"

/**
   This is the main method for our depth_sensor node
**/


int main(int argc, char **argv){

    printf("got here0\n");

    std::unique_ptr<QuboNode> node;
    
    if(strcmp(argv[1], "tortuga") == 0) {
        node.reset(new JoyReader(argc, argv, 10));
    }else{
        ROS_ERROR("the passed in arguments to thruster node (%s) doesn't match anything that makes sense..\n", argv[1]);
        exit(1);
    }


    while (ros::ok()){
        node->update();
        node->publish();
    }

}

