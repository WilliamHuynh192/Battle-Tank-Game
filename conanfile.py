from conan import ConanFile
from conan.tools.cmake import cmake_layout


class BattleTankRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"


    def requirements(self):
        self.requires("sdl/2.30.5")

    def build_requirements(self):
        self.tool_requires("cmake/3.28.1")
