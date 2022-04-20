cmake_minimum_required(VERSION 3.22)
project(mc_inventory_mockup)

set(CMAKE_CXX_STANDARD 14)

include_directories(persistence)


add_executable(mc_inventory_mockup
        persistence/Repo.cpp
        persistence/Repo.h
        exceptions/RepoException.cpp
        exceptions/RepoException.h)
