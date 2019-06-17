/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: Node.h
*
*          Created On: Mon 27 May 2019 06:04:03 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#ifndef BASE_NODE_H_
#define BASE_NODE_H

#include <chrono>
#include <iostream>
#include <ros/ros.h>
#include <stdio.h>

#include "absl/memory/memory.h"
#include "absl/strings/str_cat.h"
#include "Options.h"

namespace base {

class Node {
public:
  Node(const Options &options);
  ~Node();
  void Init();
  void Run();

public:
  ::ros::NodeHandle node_handle_;

private:
  Options options_;
};

} // namespace base

#endif
