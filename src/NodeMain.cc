/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: NodeMain.cc
*
*          Created On: Mon 27 May 2019 05:26:41 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#include "Node.h"

DEFINE_string(configuration_directory, "",
              "First directory in which configuration files are searched, "
              "second is always the Cartographer installation to allow "
              "including files from there.");
DEFINE_string(configuration_basename, "",
              "Basename, i.e. not containing any directory prefix, of the "
              "configuration file.");

using namespace base;

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, true);

  CHECK(!FLAGS_configuration_directory.empty())
      << "-configuration_directory is missing.";
  CHECK(!FLAGS_configuration_basename.empty())
      << "-configuration_basename is missing.";

  Options options =
      LoadOptions(FLAGS_configuration_directory, FLAGS_configuration_basename);

  FLAGS_minloglevel = options.log_level;
  FLAGS_logtostderr = true;
  FLAGS_colorlogtostderr = true;

  ::ros::init(argc, argv, "base");
  ::ros::start();

  Node node(options);
  node.Init();
  node.Run();

  ::ros::spin();
  ::ros::shutdown();
}
