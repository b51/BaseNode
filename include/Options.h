/*************************************************************************
 *
 *              Author: b51
 *                Mail: b51live@gmail.com
 *            FileName: Options.h
 *
 *          Created On: Mon 27 May 2019 05:32:38 PM CST
 *     Licensed under The MIT License [see LICENSE for details]
 *
 ************************************************************************/

#ifndef BASE_OPTIONS_H_
#define BASE_OPTIONS_H_

#include <string>
#include <tuple>
#include <vector>

#include "cartographer/common/configuration_file_resolver.h"
#include "cartographer/common/lua_parameter_dictionary.h"
#include "cartographer/common/port.h"
#include "glog/logging.h"

namespace base {
namespace carto = cartographer;

struct Options {
  int log_level;
};

inline Options CreateOptions(
    carto::common::LuaParameterDictionary* const lua_parameter_dictionary) {
  Options options;
  options.log_level = lua_parameter_dictionary->GetInt("log_level");
  return options;
}

inline Options LoadOptions(const std::string& configuration_directory,
                           const std::string& configuration_basename) {
  auto file_resolver =
      absl::make_unique<carto::common::ConfigurationFileResolver>(
          std::vector<std::string>{configuration_directory});
  const std::string code =
      file_resolver->GetFileContentOrDie(configuration_basename);
  carto::common::LuaParameterDictionary lua_parameter_dictionary(
      code, std::move(file_resolver));

  return CreateOptions(&lua_parameter_dictionary);
}

}  // namespace base

#endif
