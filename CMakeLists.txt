cmake_minimum_required(VERSION 3.22)
project(mc_inventory_mockup)

set(CMAKE_CXX_STANDARD 17)

include_directories(persistence)
include_directories(exceptions)
include_directories(domain)
include_directories(service)



add_executable(mc_inventory_mockup
        persistence/Repo.h
        exceptions/RepoException.hpp
        domain/IItem.cpp
        domain/IItem.h
        domain/stackable/StackableItem.cpp
        domain/stackable/StackableItem.h
        service/InventoryService.cpp
        service/InventoryService.h
        domain/unstackable/UnstackableItem.cpp
        domain/unstackable/UnstackableItem.h
        domain/stackable/Consumable.cpp
        domain/stackable/Consumable.h
        main.cpp
        domain/unstackable/Armour.cpp
        domain/unstackable/Armour.h
        domain/unstackable/Weapon.cpp
        domain/unstackable/Weapon.h
        persistence/Repo.cpp
        service/EnchantmentService.cpp
        service/EnchantmentService.h
        exceptions/EnchantException.hpp
        interface/CLI.cpp
        interface/CLI.h persistence/Domain.cpp persistence/Domain.h domain/Command.cpp domain/Command.h persistence/Commands.cpp persistence/Commands.h)
