workspace "Game"
    architecture "x64"

    configurations {
        "Debug",
        "Release"
    }

    startproject "DungeonWarrior"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "DungeonWarrior"