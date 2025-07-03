# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TrasaMiasta_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TrasaMiasta_autogen.dir\\ParseCache.txt"
  "TrasaMiasta_autogen"
  )
endif()
