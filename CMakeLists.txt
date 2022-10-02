cmake_minimum_required(VERSION 2.8)

project(swig-example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter -fPIC")

# Add liba
add_library(ospell
			ospell.cc
			ZHfstOspeller.cc    ZHfstOspeller.h
			hfst-ol.cc      hfst-ol.h
			hfstol-stdafx.h
			ZHfstOspellerXmlMetadata.cc
			ZHfstOspellerXmlMetadata.h
        	)

# Set up public headers for liba
set_target_properties(ospell PROPERTIES PUBLIC_HEADER "ospell.h")

# Create main and link to liba
add_library(${PROJECT_NAME} swig-example.cpp)
target_link_libraries(${PROJECT_NAME} ospell)

# Set up public headers for swig-example
set_target_properties(swig-example PROPERTIES PUBLIC_HEADER "swig-example.h")

# Add install target
install(TARGETS ${PROJECT_NAME} ospell
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        PUBLIC_HEADER DESTINATION include)

# Add swig subdirectory
add_subdirectory(swig)
