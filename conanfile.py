from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake, CMakeDeps


class BattleTankRecipe(ConanFile):
    name = "battle_tank"
    version = "1.0"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("sdl/2.30.5")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
