cmake_minimum_required(VERSION 3.10)
project(ExpertSystem)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(ExpertSystem
    src/main.cpp
    src/KnowledgeBase.cpp
    src/InferenceEngine.cpp
    src/ExplanationEngine.cpp
)