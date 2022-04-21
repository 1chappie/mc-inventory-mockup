cmake_minimum_required(VERSION 3.22)
project(mc_inventory_mockup)

set(CMAKE_CXX_STANDARD 17)

include_directories(persistence)
include_directories(exceptions)
include_directories(domain)
include_directories(service)



add_executable(mc_inventory_mockup
        persistence/Repo.h
        exceptions/RepoException.cpp
        exceptions/RepoException.h
        domain/Item.cpp
        domain/Item.h
        domain/StackableItem.cpp
        domain/StackableItem.h
        service/ItemService.cpp
        service/ItemService.h
        domain/UnstackableItem.cpp
        domain/UnstackableItem.h
        domain/Consumable.cpp
        domain/Consumable.h
        main.cpp domain/Armour.cpp domain/Armour.h domain/Weapon.cpp domain/Weapon.h)
