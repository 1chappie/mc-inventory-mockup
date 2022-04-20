cmake_minimum_required(VERSION 3.22)
project(mc_inventory_mockup)

set(CMAKE_CXX_STANDARD 14)

include_directories(persistence)
include_directories(exceptions)
include_directories(domain)
include_directories(service)



add_executable(mc_inventory_mockup
        persistence/Repo.h
        exceptions/RepoException.cpp
        exceptions/RepoException.h
        domain/IItem.cpp
        domain/IItem.h
        domain/StackableItem.cpp
        domain/StackableItem.h
        service/ItemService.cpp
        service/ItemService.h domain/UnstackableItem.cpp domain/UnstackableItem.h)
