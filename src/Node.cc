/*************************************************************************
 *
 *              Author: b51
 *                Mail: b51live@gmail.com
 *            FileName: Node.cc
 *
 *          Created On: Mon 27 May 2019 05:28:32 PM CST
 *     Licensed under The MIT License [see LICENSE for details]
 *
 ************************************************************************/

#include "Node.h"

namespace base {

Node::Node(const Options& options) : options_(options) {
  LOG(INFO) << "log_level                   : " << options.log_level;
}

Node::~Node() {}

void Node::Init() { LOG(INFO) << "base node init"; }

void Node::Run() {
  while (node_handle_.ok()) {
    // double current_time = GetTime();
    ::ros::spinOnce();
  }
}

}  // namespace base
